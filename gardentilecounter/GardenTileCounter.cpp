#include "GardenTileCounter.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <blib/Renderer.h>
#include <blib/LineBatch.h>
#include <blib/ResourceManager.h>
#include <blib/Window.h>
#include <blib/StaticModel.h>
#include <blib/Math.h>
#include <blib/Color.h>


GardenTileCounter::GardenTileCounter()
{
	appSetup.renderer = blib::AppSetup::GlRenderer;
	appSetup.window.setWidth(1920);// resolution.x - 100;
	appSetup.window.setHeight(1079);// resolution.y - 100;
	appSetup.border = false;
	appSetup.icon = 0;
	appSetup.vsync = false;
	appSetup.title = "Garden Tiles";
	appSetup.vsync = true;


}


void GardenTileCounter::init()
{
/*	outline.push_back(glm::vec2(0, 0));
	outline.push_back(glm::vec2(304, 0));
	outline.push_back(glm::vec2(302, 470));
	outline.push_back(glm::vec2(562, 470));
	outline.push_back(glm::vec2(562, 1083));
	outline.push_back(glm::vec2(336, 1083));
	outline.push_back(glm::vec2(462, 1366)); // move 336 a bit to the right for the path
	outline.push_back(glm::vec2(462, 1467));
	outline.push_back(glm::vec2(282, 1467));
	outline.push_back(glm::vec2(282, 1362));
	//path
	outline.push_back(glm::vec2(102, 990));
	outline.push_back(glm::vec2(0, 990));*/


	outline.push_back(glm::vec2(0, 0));
	outline.push_back(glm::vec2(300, 0));
	outline.push_back(glm::vec2(300, 470));
	outline.push_back(glm::vec2(560, 470));
	outline.push_back(glm::vec2(560, 1080));
	outline.push_back(glm::vec2(336, 1080));
	outline.push_back(glm::vec2(460, 1366));
	outline.push_back(glm::vec2(460, 1467));
	outline.push_back(glm::vec2(280, 1467));
	outline.push_back(glm::vec2(280, 1362));
	//path
	outline.push_back(glm::vec2(102, 990));
	outline.push_back(glm::vec2(0, 990));



	glm::vec2 corner(0, 0);

	for (int i = 0; i < 400; i++)
	{
		blib::math::Polygon p({ corner + glm::vec2(0, 0), corner + glm::vec2(60, 0), corner + glm::vec2(60, 40), corner + glm::vec2(0, 40), });
		p.intersect(outline);
		if (!p.empty())
		{
			tiles.push_back(p);
		}



		corner.x += 60;
		if (corner.x > 550)
		{
			corner.y += 40;
			corner.x = ((int)(corner.y / 40) % 3) * -20;
		}
	}

}


void GardenTileCounter::update(double elapsedTime)
{
	if (keyState.isPressed(blib::Key::ESC))
		running = false;
	lastKeyState = keyState;
}

void GardenTileCounter::draw()
{
	renderer->clear(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f), blib::Renderer::Color | blib::Renderer::Depth);

	glm::mat4 camera;
	camera = blib::math::easyMatrix(glm::vec2(200, 300), -90.0f, glm::vec2(-1.0f,1.0f));


	lineBatch->begin(camera);
	lineBatch->draw(outline, blib::Color::black);

	for (blib::math::Polygon& p : tiles)
	{
		lineBatch->draw(p, blib::Color::blue);
	}

	lineBatch->end();

}

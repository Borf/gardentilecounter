#pragma once

#include <blib/App.h>
#include <blib/RenderState.h>
#include <blib/gl/Vertex.h>

#include <blib/math/Polygon.h>

namespace blib
{
	class Texture;
	class StaticModel;
}


class GardenTileCounter : public blib::App
{
public:
	blib::math::Polygon outline;

	std::vector<blib::math::Polygon> tiles;
	
	std::vector<blib::math::Polygon> leftovers;



	blib::KeyState lastKeyState;

	GardenTileCounter();
	virtual void init();
	virtual void update(double elapsedTime);
	virtual void draw();

};
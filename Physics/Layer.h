#pragma once
#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int const WEIGHT = 1000;
int const HEIGHT = 900;

class Layer {

	float x, y, r, dx, dy;
	Color col;

public:

	Layer();

	float GetX();
	void SetX(float x);
	float GetY();
	void SetY(float y);
	float GetDx();
	void SetDx(float dx);
	float GetDy();
	void SetDy(float dy);
	float GetR();
	Color GetCol();

};
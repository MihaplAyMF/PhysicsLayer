

#include "Layer.h"

Layer::Layer() {
	x = (rand() % (WEIGHT - 100)) + 50;
	y = (rand() % (HEIGHT - 100)) + 50;
	r = rand() % 20 + 10.0;
	dx = (rand() % 20)-10 / 1.0;
	dy = (rand() % 20)-10 / 1.0;
	col = Color(rand() % 256, rand() % 256, rand() % 256);
}

float Layer::GetX() {
	return x;
}

void Layer::SetX(float x) {
	this->x = x;
}

float Layer::GetY() {
	return y;
}

void Layer::SetY(float y) {
	this->y = y;
}

float Layer::GetDx() {
	return dx;
}

void Layer::SetDx(float dx) {
	this->dx = dx;
}

float Layer::GetDy() {
	return dy;
}

void Layer::SetDy(float dy) {
	this->dy = dy;
}

float Layer::GetR() {
	return r;
}

Color Layer::GetCol() {
	return col;
}

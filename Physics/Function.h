#pragma once

#include <iostream>
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Layer.h"

using namespace sf;

void swap(float& a, float& b);
void collizionWall(Layer A[], int size);
void collizionLayer(Layer A[], int size);
void detectedLayer(Layer& A, Layer& B, float dt, float sin, float cos);
void drawLayer(Layer A[], CircleShape shape, RenderWindow& window, int size);
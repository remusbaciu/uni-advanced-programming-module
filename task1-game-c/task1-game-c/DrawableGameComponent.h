#pragma once
#include <iostream>
#include <string>
#include "GameComponent.h"
#include "Direction.h"

using namespace std;

class DrawableGameComponent : public GameComponent {

public:
	DrawableGameComponent(int paramX, int paramY) {
		x = paramX;
		y = paramY;
	};

	Direction direction = Right;
	const int HEIGHT = 20;
	const int WIDTH = 80;
	void Update(const tm* time) override;

private:
	void ChangeDirection();
	void Draw();
	void CalculatePosition();
	int x;
	int y;
	string currentDirection;
};

void DrawableGameComponent::CalculatePosition() {
	switch (direction) {
	case Up:
		y++;
		if (y > HEIGHT) { y = HEIGHT; };
		currentDirection = "Up";
		break;
	case Down:
		y--;
		if (y < 0) { y = 0; }
		currentDirection = "Down";
		break;
	case Left:
		x--;
		if (x < 0) { x = 0; }
		currentDirection = "Left";
		break;
	case Right:
		x++;
		if (x > WIDTH) { x = WIDTH; }
		currentDirection = "Right";
		break;
	default:
		break;
	}
}

void DrawableGameComponent::Update(const tm* time) {
	GameComponent::Update(time);
	CalculatePosition();
	Draw();
	ChangeDirection();
};

void DrawableGameComponent::Draw() {
	cout << currentDirection << " : " << "x:" << x << " y:" << y << endl;
};

void DrawableGameComponent::ChangeDirection() {
	srand(time(NULL));
	int randomNumber = (rand() % 4) + 1;
	while (randomNumber == direction)
		randomNumber = (rand() % 4) + 1;
	direction = static_cast<Direction>(randomNumber);
};

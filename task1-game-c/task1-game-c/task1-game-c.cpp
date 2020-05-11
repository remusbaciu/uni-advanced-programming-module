#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"
#include <iostream>

void Initialise() {
	cout << "Game Initialised" << endl;
};

void Terminate() {
	cout << "Game Terminated" << endl;
};


int main()
{
	Game game(5);

	GameComponent* gameComponent;
	DrawableGameComponent* drawable;

	gameComponent = new GameComponent();
	drawable = new DrawableGameComponent(1, 3);

	game.SetInitialise(*Initialise);
	game.SetTerminate(*Terminate);

	game.Add(gameComponent);
	game.Add(drawable);

	game.Run();
}

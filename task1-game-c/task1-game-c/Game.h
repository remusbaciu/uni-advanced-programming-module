#pragma once
#include <iostream>
#include <chrono>  
#include <thread> 
#include "GameComponent.h"

using namespace std;

class Game {
public:
	Game(int max) {
		this->max = max;
	};
	void Add(GameComponent* gameComponent);
	void Run();
	void SetInitialise(void (*init)());
	void SetTerminate(void(*term)());
private:
	int numberOfComponents = 0;
	int max;
	const int SEC_1 = 1000;
	const int TOTAL_RUNS = 5;

	GameComponent* components[5];
	void (*initialise)();
	void (*terminate)();
};

void Game::SetInitialise(void (*init)()) {
	initialise = *init;
};

void Game::SetTerminate(void (*term)()) {
	terminate = *term;
};

void Game::Add(GameComponent* gameComponent) {
	if (numberOfComponents != max) {
		components[numberOfComponents] = gameComponent;
		numberOfComponents++;
	}
	else {
		return;
	}
};

void Game::Run() {
	(*initialise)();
	for (int i = 0; i < TOTAL_RUNS; i++) {
		for (int i = 0; i < numberOfComponents; i++) {
			time_t rawtime = time(0);
			components[i]->Update(localtime(&rawtime));
		}
	}
	(*terminate)();
};

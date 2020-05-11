#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class GameComponent {
public:
	GameComponent() {
		id = ++instances;
	};
	~GameComponent() {
		--id;
	}
	virtual void Update(const tm* time);
private:
	int id;
	static int instances;
};

int GameComponent::instances;

void GameComponent::Update(const tm* time) {
	cout << "id : " << id << " updated at : " << put_time(time, "%X") << endl;
};

#pragma once
#include "Player.h"
#include "Platform.h"
#include "Ogre.h"
using namespace Ogre;
using namespace std;

class PhysicsManager
{
public:

	PhysicsManager();
	virtual ~PhysicsManager() {}


	void Setup();
	void UpdatePlayer(Player* p);

	float GravityInt;
	Vector3 Gravity;
	
};


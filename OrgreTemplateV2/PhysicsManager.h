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


	void Setup(SceneNode* c);
	void UpdatePlayer(Player* p, Real deltatime, Vector3 ptrans);

	float GravityInt;
	Vector3 Gravity;
	SceneNode* camref;
	
};


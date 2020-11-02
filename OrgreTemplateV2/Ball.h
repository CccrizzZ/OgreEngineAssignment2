#pragma once
#include "Ogre.h"

using namespace Ogre;

class Ball
{
public:
	Ball();
	virtual ~Ball(){};

	void setup(SceneManager* scnMgr, Vector3 position, Vector3 scale);
	void update();
	void move();

	
	Entity* ballEntity;
	SceneNode* ballNode;
	int ballSpeed = 2;

	int XVelocity = 2;
	int YVelocity = 2;

};


#pragma once
#include "Ogre.h"

using namespace Ogre;

class Bat
{
public:

	Bat();
	virtual ~Bat() {}

	
	void setup(SceneManager* scnMgr, Vector3 position, Vector3 scale);
	void update();
	void moveRight();
	void moveLeft();
	
	Entity* batEntity;
	SceneNode* batNode;
	int batSpeed = 2;

};


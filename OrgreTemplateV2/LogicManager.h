#pragma once
#include "Player.h"
#include "Platform.h"
#include "Ogre.h"
#include <iostream>
#include <vector>
using namespace Ogre;
using namespace std;

class LogicManager
{
public:
	LogicManager();
	virtual ~LogicManager() {}


	void Update();
	void Setup(SceneManager* scnMgr);
	bool CollisionDetectionAABB(Entity* e1, Entity* e2);
	void CameraMover(Camera& cam, Player& p);
	void MoveRandomPlatform(SceneManager* scnMgr, Camera* cam);

	int Score;
	std::vector<Platform*> pVector;

};


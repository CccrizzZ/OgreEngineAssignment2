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
	void Setup(SceneManager* scnMgr, Player* p);
	bool CollisionDetectionTopOnly(SceneNode* s1, SceneNode* s2);
	void CameraMover(SceneNode* cam, Player* p, Real deltatime);
	void MoveRandomPlatform(SceneManager* scnMgr, Camera* cam);

	int Score;
	std::vector<Platform*> pVector;

	Player* pref;

};


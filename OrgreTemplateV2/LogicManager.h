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
	bool CollisionDetectionBotOnly(SceneNode* player, SceneNode* platform);
	void CameraMover(SceneNode* cam, Player* p, Real deltatime);
	void MoveRandomPlatform(SceneManager* scnMgr, SceneNode* cam);

	int Score;
	std::vector<Platform*> pVector;

	Player* pref;
	MaterialPtr PlatformMaterial;
	Vector3 cameraSpeed;
};


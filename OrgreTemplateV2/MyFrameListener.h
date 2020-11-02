#pragma once
#include "OgreFrameListener.h"
#include "Player.h"
#include "Platform.h"
#include "LogicManager.h"
#include "PhysicsManager.h"
using namespace Ogre;


class MyFrameListener : public FrameListener
{

private:

	Player* pref;

	SceneNode* _PlayerNode;
	SceneNode* _BackGroundNode;
	SceneNode* _CameraNode;

	// Managers
	LogicManager* LogicMgr;
	PhysicsManager* PhysicMgr;
	SceneManager* SceneMgr;

public:

	// Game.cpp manipulates this variable
	Vector3 PlayerTranslate;

	MyFrameListener(SceneManager* scMgr, Player* p, SceneNode* playerNode, SceneNode* bgNode, SceneNode* camNode)
	{
		pref = p;

		_PlayerNode = playerNode;
		_BackGroundNode = bgNode;
		_CameraNode = camNode;

		SceneMgr = scMgr;

		LogicMgr = new LogicManager();
		PhysicMgr = new PhysicsManager();
		
		LogicMgr->Setup(SceneMgr);
		PhysicMgr->Setup();

	}

	bool frameStarted(const Ogre::FrameEvent& evt)
	{


		_PlayerNode->translate(PlayerTranslate * evt.timeSinceLastFrame * 10);
		
		PhysicMgr->UpdatePlayer(pref);


		_BackGroundNode->setPosition(_CameraNode->getPosition() + Vector3(0, 0, -400));

		//_CameraNode->setPosition(_PlayerNode->getPosition() + Vector3(0, 47, 222));

		//_camNode->translate(translate * evt.timeSinceLastFrame * _movementspeed);
		//_sceneNode->translate(translate * evt.timeSinceLastFrame * _movementspeed);
		//translate = Ogre::Vector3(0, 0, 0);
		//rotX = 0.0f;
		//rotY = 0.0f;

		return true;
	}
};
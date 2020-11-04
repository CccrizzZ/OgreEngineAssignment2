#pragma once
#include "OgreFrameListener.h"
#include "Player.h"
#include "Platform.h"
#include "LogicManager.h"
#include "PhysicsManager.h"
#include "AManager.h"

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
	AManager* AudioMgr;



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
		AudioMgr = new AManager();

		LogicMgr->Setup(SceneMgr, p);
		PhysicMgr->Setup();

	}

	bool frameStarted(const Ogre::FrameEvent& evt)
	{

		// move the player according to keyboard input
		//_PlayerNode->translate(PlayerTranslate * evt.timeSinceLastFrame * 10);
		
		// update player according to gravity
		PhysicMgr->UpdatePlayer(pref, evt.timeSinceLastFrame, PlayerTranslate);


		// move camera according to player y position
		LogicMgr->CameraMover(_CameraNode, pref, evt.timeSinceLastFrame);


		// set background position according to camera position
		_BackGroundNode->setPosition(_CameraNode->getPosition() + Vector3(0, 0, -600));

		LogicMgr->Update();

		//_CameraNode->setPosition(_PlayerNode->getPosition() + Vector3(0, 47, 222));


		return true;
	}
};
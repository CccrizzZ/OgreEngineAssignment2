#pragma once
#include "Ogre.h"
using namespace Ogre;


class Player
{
public:
	Player();
	virtual ~Player() {}


	void Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale);
	void update();
	void Move(Vector3 Grav);

	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void Bounce();

	Vector3 GetPosition();


	Vector3 PlayerGravity;


	Entity* PlayerEntity;
	SceneNode* PlayerNode;


};


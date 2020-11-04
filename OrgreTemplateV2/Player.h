#pragma once
#include "Ogre.h"
#include <iostream>
using namespace Ogre;
using namespace std;


class Player
{
public:
	Player();
	virtual ~Player() {}


	void Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale, MaterialPtr pmat);
	void update();
	void Move(Vector3 Grav, Real dt, Vector3 Ptranslate, Vector3 campos);

	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	void Bounce();

	Vector3 GetPosition();
	Vector3 GetScale();

	Vector3 PlayerAcceleration;
	Vector3 tempAcc;

	Entity* PlayerEntity;
	SceneNode* PlayerNode;

	float JumpLimit;
	bool Jumping;
	float jumpPosY;
	bool isCollide;
	int score;

};


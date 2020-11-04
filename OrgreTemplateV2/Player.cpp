#include "Player.h"

Player::Player()
{
	PlayerAcceleration = Vector3(0, 0, 0);
	JumpLimit = 60;
	Jumping = false;
}

void Player::Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale, MaterialPtr pmat)
{
	PlayerNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	PlayerNode->setPosition(position);
	PlayerNode->setScale(scale);

	PlayerEntity = scnMgr->createEntity(scnMgr->PT_PLANE);

	PlayerNode->attachObject(PlayerEntity);
	PlayerEntity->setMaterial(pmat);

}

void Player::update()
{

}

void Player::Move(Vector3 Grav, Real dt, Vector3 Ptranslate, Vector3 campos)
{




	if (Jumping)
	{
		// while jumping
		PlayerAcceleration = -tempAcc;
		PlayerNode->translate(PlayerAcceleration * dt * 80);
		tempAcc += Vector3(0, 0.1f, 0);
	}
	else
	{
		isCollide = false;
		// while falling
		PlayerAcceleration = Grav;
		PlayerNode->translate(PlayerAcceleration * dt * 80);
	}

	// if collided with platform
	if (GetPosition().y <= campos.y -85  || isCollide)
	{
		// save gravity and jump start position
		tempAcc = Grav;
		jumpPosY = GetPosition().y;
		Jumping = true;
	}

	// if reached jump limit set jumping to false
	if (GetPosition().y - jumpPosY > JumpLimit)
	{
		Jumping = false;
		isCollide = false;
	}


	// left right movement
	PlayerNode->translate(Ptranslate * dt * 10);
	isCollide = false;


	//cout << GetPosition().y << "\n";
	
}


void Player::SetPosition(float x, float y, float z)
{
	PlayerNode->setPosition(Vector3(x, y, z));
}

void Player::SetPosition(Vector3 position)
{
	PlayerNode->setPosition(position);

}

void Player::Bounce()
{
	score += 100;
	isCollide = true;
}

Vector3 Player::GetPosition()
{
	return Vector3(PlayerNode->getPosition());
}

Vector3 Player::GetScale()
{
	return PlayerNode->getScale();
}



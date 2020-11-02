#include "Player.h"

Player::Player()
{
	PlayerGravity = Vector3(0, 0, 0);
}

void Player::Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale)
{
	PlayerNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	PlayerNode->setPosition(position);
	PlayerNode->setScale(scale);

	//PlayerEntity = scnMgr->createEntity(scnMgr->PT_CUBE);
	PlayerEntity = scnMgr->createEntity("fish.mesh");

	PlayerNode->attachObject(PlayerEntity);

}

void Player::update()
{

}

void Player::Move(Vector3 Grav)
{

	PlayerGravity = Grav;
	
	
	SetPosition(GetPosition() + PlayerGravity);


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
	SetPosition(GetPosition() - PlayerGravity*100);
}

Vector3 Player::GetPosition()
{
	return Vector3(PlayerNode->getPosition());
}

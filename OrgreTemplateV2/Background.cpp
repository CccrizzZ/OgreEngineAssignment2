#include "Background.h"

Background::Background()
{
}

void Background::Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale)
{
	BackgroundNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	BackgroundNode->setPosition(position);
	BackgroundNode->setScale(scale);

	BackgroundEntity = scnMgr->createEntity("ogrehead.mesh");
	BackgroundNode->attachObject(BackgroundEntity);
}

void Background::SetPosition(float x, float y, float z)
{
	BackgroundNode->setPosition(Vector3(x, y, z));

}


void Background::SetPosition(Vector3 position)
{
	BackgroundNode->setPosition(position);

}

Vector3 Background::GetPosition()
{
	return Vector3(BackgroundNode->getPosition());
}

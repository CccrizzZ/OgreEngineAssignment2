#include "Platform.h"

Platform::Platform()
{
}

void Platform::Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale)
{
	PlatformNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	PlatformNode->setPosition(position);
	PlatformNode->setScale(pSize);

	PlatformEntity = scnMgr->createEntity(scnMgr->PT_CUBE);
	PlatformNode->attachObject(PlatformEntity);
}

void Platform::Update()
{
}

void Platform::SetPosition(float x, float y, float z)
{
	PlatformNode->setPosition(Vector3(x, y, z));
}

void Platform::SetPosition(Vector3 pos)
{
	PlatformNode->setPosition(pos);
}

Vector3 Platform::GetPosition()
{
	return Vector3(PlatformNode->getPosition());
}


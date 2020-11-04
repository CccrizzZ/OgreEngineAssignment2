#include "Platform.h"

Platform::Platform()
{
	pSize = Vector3(0.2f, 0.05f, 0.0f);
	
}

void Platform::Setup(SceneManager* scnMgr, Vector3 position)
{
	PlatformNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	PlatformNode->setPosition(position);
	PlatformNode->setScale(pSize);

	PlatformEntity = scnMgr->createEntity(scnMgr->PT_PLANE);
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

Vector3 Platform::GetScale()
{
	return PlatformNode->getScale();
}


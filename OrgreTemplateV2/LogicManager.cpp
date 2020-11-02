#include "LogicManager.h"

LogicManager::LogicManager()
{
}

void LogicManager::Update()
{

}

void LogicManager::Setup(SceneManager* scnMgr)
{
	Score = 0;

	srand(time(NULL));

	for (int i = 1; i < 16; i++)
	{
		Platform* tempPlatform = new Platform();

		Vector3 position = Vector3(rand() % 10 + 1, rand() % 10 + 1, 0);
		pVector.push_back(tempPlatform);

		tempPlatform->PlatformNode = scnMgr->getRootSceneNode()->createChildSceneNode();
		tempPlatform->PlatformNode->setPosition(position);
		tempPlatform->PlatformNode->setScale(tempPlatform->pSize);

		tempPlatform->PlatformEntity = scnMgr->createEntity(scnMgr->PT_CUBE);
		tempPlatform->PlatformNode->attachObject(tempPlatform->PlatformEntity);
		
	}
}

bool LogicManager::CollisionDetectionAABB(Entity* e1, Entity* e2)
{
	return false;
}

void LogicManager::CameraMover(Camera& cam, Player& p)
{
}

void LogicManager::MoveRandomPlatform(SceneManager* scnMgr, Camera* cam)
{
	



}

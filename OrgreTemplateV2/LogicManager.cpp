#include "LogicManager.h"

LogicManager::LogicManager()
{
	Score = 0;
}

void LogicManager::Update()
{
	for (int i = 0; i < pVector.size(); i++)
	{
		if (CollisionDetectionTopOnly(pref->PlayerNode, pVector[i]->PlatformNode) )
		{
			cout << "Collided" << "\n";
			
		}
		else
		{
			//cout << "Not Collided" << "\n";
			//cout << pref->GetPosition() <<"\n";

		}

	}

}

void LogicManager::Setup(SceneManager* scnMgr, Player* p)
{
	pref = p;

	srand(time(NULL));

	for (int i = 1; i < 16; i++)
	{
		Platform* tempPlatform = new Platform();

		Vector3 tempPosition = Vector3(rand() % 10, rand() % 10, 0);
		tempPlatform->Setup(scnMgr, tempPosition);
		
		pVector.push_back(tempPlatform);
		

	}
}

bool LogicManager::CollisionDetectionTopOnly(SceneNode* s1, SceneNode* s2)
{

	if (s1->getPosition().x < s2->getPosition().x + s2->getScale().x &&
		s1->getPosition().x + s1->getScale().x > s2->getPosition().x &&
		s1->getPosition().y < s2->getPosition().y + s2->getScale().y &&
		s1->getPosition().y + s1->getScale().y > s2->getScale().y
	)
	{
			return true;
	}

	return false;
}

void LogicManager::CameraMover(SceneNode* cam, Player* p, Real deltatime)
{
	if (p->GetPosition().y - cam->getPosition().y > 50)
	{
		while (cam->getPosition().y < p->GetPosition().y + 47)
		{
			cam->translate(Vector3(0, 0.01f, 0) * deltatime);

		}

	}
	
}

void LogicManager::MoveRandomPlatform(SceneManager* scnMgr, Camera* cam)
{
	



}

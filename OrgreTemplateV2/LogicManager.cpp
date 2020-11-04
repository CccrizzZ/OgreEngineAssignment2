#include "LogicManager.h"

LogicManager::LogicManager()
{
	Score = 0;
	cameraSpeed = Vector3::ZERO;
}

void LogicManager::Update()
{
	for (int i = 0; i < pVector.size(); i++)
	{
		if (CollisionDetectionBotOnly(pref->PlayerNode, pVector[i]->PlatformNode) )
		{
			cout << "Collided with: " << pVector[i]->GetPosition() << "\n";
			
			pref->Bounce();
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
	// player reference
	pref = p;
	
	// random seed
	srand(time(NULL));

	// platform material
	PlatformMaterial = Ogre::MaterialManager::getSingleton().create("plat", "General");
	PlatformMaterial->getTechnique(0)->getPass(0)->createTextureUnitState("platform.png");
	PlatformMaterial->getTechnique(0)->getPass(0)->setAlphaRejectSettings(Ogre::CMPF_GREATER_EQUAL, 128, true);
	PlatformMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	PlatformMaterial->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	PlatformMaterial->getTechnique(0)->getPass(0)->setLightingEnabled(true);

	
	for (int i = 1; i < 30; i++)
	{
		Platform* tempPlatform = new Platform();

		// setup platform with random position 
		Vector3 tempPosition = Vector3((rand() % 300) - 150, (rand() % 250) - 150, 0);
		tempPlatform->Setup(scnMgr, tempPosition, PlatformMaterial);
		
		pVector.push_back(tempPlatform);
		

	}



}

bool LogicManager::CollisionDetectionBotOnly(SceneNode* player, SceneNode* platform)
{

	if (player->getPosition().x < platform->getPosition().x + platform->getScale().x+2 &&
		player->getPosition().x + player->getScale().x+2 > platform->getPosition().x &&
		player->getPosition().y < platform->getPosition().y + platform->getScale().y+2 
		//&& player->getPosition().y + player->getScale().y > platform->getScale().y
	)
	{
			return true;
	}
	return false;
}

void LogicManager::CameraMover(SceneNode* cam, Player* p, Real deltatime)
{
	if (p->GetPosition().y - cam->getPosition().y > 30)
	{
		if (cam->getPosition().y < p->GetPosition().y + 47)
		{
			cameraSpeed += Vector3(0, 5, 0);
			cam->translate(cameraSpeed * deltatime);

		}

	}
	else 
	{
		cameraSpeed = Vector3::ZERO;
	}
	
}

void LogicManager::MoveRandomPlatform(SceneManager* scnMgr, SceneNode* cam)
{
	
	for (int i = 0; i < pVector.size(); i++)
	{
		if (pVector[i]->GetPosition().y < cam->getPosition().y - 100)
		{
			pVector[i]->SetPosition(Vector3((rand() % 300) - 150, (rand() % 250) - 150 + cam->getPosition().y, 0));
			cout << "platfrom reset!!" << "\n";
		}
	}


}

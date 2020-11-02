#pragma once
#include "Ogre.h"
using namespace Ogre;



class Background
{
public:
	Background();
	virtual ~Background() {}


	void Setup(SceneManager* scnMgr, Vector3 position, Vector3 scale);
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);

	Vector3 GetPosition();

	Entity* BackgroundEntity;
	SceneNode* BackgroundNode;



};


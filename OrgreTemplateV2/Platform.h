#pragma once
#include "Ogre.h"
using namespace Ogre;


class Platform
{
public:

	Platform();
	virtual ~Platform() {}


	void Setup(SceneManager* scnMgr, Vector3 position);
	void Update();
	
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	Vector3 GetScale();

	Vector3 pSize;

	Entity* PlatformEntity;
	SceneNode* PlatformNode;

};


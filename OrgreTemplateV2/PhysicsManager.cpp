#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
	// position += current velocity * acceleration
	// Gravity is a acceleration
	GravityInt = -2.0f;
	Gravity = Vector3(0, GravityInt, 0);
}

void PhysicsManager::Setup(SceneNode* c)
{
	camref = c;

}



void PhysicsManager::UpdatePlayer(Player* p, Real deltatime, Vector3 ptrans)
{

	// if player do xxxxxx, bounce it upwards
	//if (p->GetPosition().y < 0)
	//{
	//	p->Bounce();
	//}
	
	// move player according to gravity
	p->Move(Gravity, deltatime, ptrans, camref->getPosition());

}


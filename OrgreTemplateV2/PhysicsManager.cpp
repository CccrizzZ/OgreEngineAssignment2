#include "PhysicsManager.h"

PhysicsManager::PhysicsManager()
{
}

void PhysicsManager::Setup()
{
	// position += current velocity * acceleration
	// Gravity is a acceleration
	GravityInt = -0.98f;
	Gravity = Vector3(0, GravityInt, 0);

}



void PhysicsManager::UpdatePlayer(Player* p )
{

	// if player do xxxxxx, bounce it upwards
	if (p->GetPosition().y < 0)
	{
		p->Bounce();
	}
	
	// move player according to gravity
	p->Move(Gravity);

}


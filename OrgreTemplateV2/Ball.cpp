#include "Ball.h"

Ball::Ball()
{
}

void Ball::setup(SceneManager* scnMgr, Vector3 position, Vector3 scale)
{
    ballNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    ballEntity = scnMgr->createEntity(scnMgr->PT_CUBE);
    ballNode->setPosition(position);
    ballNode->setScale(scale);
    ballNode->attachObject(ballEntity);

}

void Ball::move()
{
    ballNode->setPosition(ballNode->getPosition() + Vector3(ballSpeed, 0, 0));

}

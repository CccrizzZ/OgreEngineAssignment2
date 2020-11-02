#include "Bat.h"

Bat::Bat()
{

}

void Bat::setup(SceneManager* scnMgr,  Vector3 p, Vector3 s)
{
    batNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    batEntity = scnMgr->createEntity(scnMgr->PT_CUBE);
    batNode->setPosition(p);
    batNode->setScale(s);
    batNode->attachObject(batEntity);
}

void Bat::update()
{


}

void Bat::moveRight()
{
    if (batNode->getPosition().x <= 64)
    {

        batNode->setPosition(batNode->getPosition() + Vector3(batSpeed,0,0));
    }



}

void Bat::moveLeft()
{
    if (batNode->getPosition().x >= -64)
    {
        batNode->setPosition(batNode->getPosition() + Vector3(-batSpeed, 0, 0));
    }
}



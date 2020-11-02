#include "Game.h"
#include <string.h>
using namespace std;


Game::Game() : ApplicationContext("Doodle")
{
    playerOBJ = new Player();
    backgroundOBJ = new Background();
    
}


void Game::CoreSetup()
{

    //call the base
    ApplicationContext::setup();
    addInputListener(this);

    // get a pointer to the already created root
    root = getRoot();
    scnMgr = root->createSceneManager();



    // register scene 
    shadergen = RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);


    // light
    scnMgr->setAmbientLight(ColourValue(0.5, 0.5, 0.5));
    light = scnMgr->createLight("MainLight");
    lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    this->lightNode->attachObject(light);
    this->lightNode->setPosition(-80, 80, 50);


    // camera
    cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->attachObject(cam);
    camNode->setPosition(0, 0, 140);
    getRenderWindow()->addViewport(cam);
}




void Game::UISetup()
{
    // tray manager
    mTrayMgr = new TrayManager("TrayMngr", getRenderWindow());


    // must add Overlay System to add a tray
    scnMgr->addRenderQueueListener(mOverlaySystem);


    // add listener to tray manager
    addInputListener(mTrayMgr);


    // // Ogre Logo
    // mTrayMgr->showLogo(TL_TOPRIGHT);


    // FPS n stuff
    mTrayMgr->showFrameStats(TL_TOPLEFT);
    mTrayMgr->toggleAdvancedFrameStats();    



    // parse score into string
    string scoreStr = to_string(score);

    // Label with text 1
    // Score label
    mInfoLabel = mTrayMgr->createLabel(TL_TOPRIGHT, "GameInfo", "Score: " + score, 180);

    // // Label with text 2
    // // Unused
    // StringVector names;
    // names.push_back("This is a Doodle Jump Clone");
    // mTrayMgr->createParamsPanel(TL_TOPLEFT, "Help", 350, names)->setParamValue(0, "H/F1");

    mTrayMgr->hideCursor();







}

void Game::createFrameListener()
{
    FrameLsnr = new MyFrameListener(scnMgr, playerOBJ, playerOBJ->PlayerNode, backgroundOBJ->BackgroundNode, camNode);
    mRoot->addFrameListener(FrameLsnr);
}




void Game::setup()
{
    // set up basic stuff
    CoreSetup();

    // set up UI
    UISetup();

    playerOBJ->Setup(scnMgr, Vector3(0, 48, 0), Vector3(2.0f, 3.0f, 0.0f));
    playerOBJ->PlayerNode->roll(Degree(-90));
    backgroundOBJ->Setup(scnMgr, Vector3(0,0,0), Vector3(10,10,1));
    
    // create frame listener
    // for per frame Update
    createFrameListener();

    // //! [entity1]
    // Entity* ogreEntity = scnMgr->createEntity("ogrehead.mesh");
    // //! [entity1]

    // //! [entity1node]
    // SceneNode* ogreNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    // //! [entity1node]

    // //! [entity1nodeattach]
    // ogreNode->attachObject(ogreEntity);
    // //! [entity1nodeattach]


    // // ! [cameramove]
    camNode->setPosition(0, 47, 222);
    // // ! [cameramove]

    // //! [entity2]
    // Entity* ogreEntity2 = scnMgr->createEntity("ogrehead.mesh");
    // SceneNode* ogreNode2 = scnMgr->getRootSceneNode()->createChildSceneNode(Vector3(84, 48, 0));
    // ogreNode2->attachObject(ogreEntity2);
    // //! [entity2]

    // //! [entity3]
    // Entity* ogreEntity3 = scnMgr->createEntity("ogrehead.mesh");
    // SceneNode* ogreNode3 = scnMgr->getRootSceneNode()->createChildSceneNode();
    // ogreNode3->setPosition(0, 104, 0);
    // ogreNode3->setScale(2, 1.2, 1);
    // ogreNode3->attachObject(ogreEntity3);
    // //! [entity3]

    //! [entity4]
    Entity* ogreEntity4 = scnMgr->createEntity(scnMgr->PT_CUBE);
    ogreNode4 = scnMgr->getRootSceneNode()->createChildSceneNode();
    ogreNode4->setPosition(0, 0, 0);
    ogreNode4->setScale(0.5f, 0.1f, 0.0f);
    ogreNode4->roll(Degree(0));
    ogreNode4->attachObject(ogreEntity4);
    //! [entity4]




    //scnMgr->showBoundingBoxes(true);


}




bool Game::keyPressed(const KeyboardEvent& evt)
{
    switch (evt.keysym.sym)
    {
    case SDLK_ESCAPE:
        getRoot()->queueEndRendering();
        break;
    case 'w':

        break;
    case 's':

        break;
    case 'a':
        FrameLsnr->PlayerTranslate = Vector3(-10, 0, 0);

        break;
    case 'd':
        FrameLsnr->PlayerTranslate = Vector3(10, 0, 0);


        break;
    default:
        break;
    }
    return true;
}

bool Game::keyReleased(const KeyboardEvent& evt)
{
    switch (evt.keysym.sym)
    {
    case 'a':
        FrameLsnr->PlayerTranslate = Vector3(0, 0, 0);

        break;
    case 'd':
        FrameLsnr->PlayerTranslate = Vector3(0, 0, 0);
        
        break;
    default:
        break;
    }
    return true;
}

void Game::frameRendered(const FrameEvent& evt)
{
     
}

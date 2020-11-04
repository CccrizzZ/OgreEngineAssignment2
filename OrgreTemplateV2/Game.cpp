#include "Game.h"



Game::Game() : ApplicationContext("Doodle")
{
    playerOBJ = new Player();
    backgroundOBJ = new Background();


}

Game::~Game()
{
    if (root)
    {
        delete[] root;
        root = 0;
    }
    if (rect)
    {
        delete[] rect;
        rect = 0;
    }
    if (playerOBJ)
    {
        delete[] playerOBJ;
        playerOBJ = 0;
    }
    if (backgroundOBJ)
    {
        delete[] backgroundOBJ;
        backgroundOBJ = 0;
    }
    
    if (FrameLsnr)
    {
        delete[] FrameLsnr;
        FrameLsnr = 0;
    }

        if (mTrayMgr)
    {
        delete[] mTrayMgr;
        mTrayMgr = 0;
    }
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
    scnMgr->setAmbientLight(ColourValue(0.5f, 0.5f, 0.5f));
   // light = scnMgr->createLight("MainLight");
   // lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    //this->lightNode->attachObject(light);
    //this->lightNode->setPosition(-80, 80, 50);


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

void Game::MaterialSetup()
{
    PlayerMaterial = Ogre::MaterialManager::getSingleton().create("doodle", "General");
    PlayerMaterial->getTechnique(0)->getPass(0)->createTextureUnitState("doodle.png");
    PlayerMaterial->getTechnique(0)->getPass(0)->setAlphaRejectSettings(Ogre::CMPF_GREATER_EQUAL, 128, true);
    PlayerMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    PlayerMaterial->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
    PlayerMaterial->getTechnique(0)->getPass(0)->setLightingEnabled(true);




    //// Create background material
    BackGroundMaterial = Ogre::MaterialManager::getSingleton().create("Background", "General");
    BackGroundMaterial->getTechnique(0)->getPass(0)->createTextureUnitState("background.png");
    BackGroundMaterial->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
    BackGroundMaterial->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
    BackGroundMaterial->getTechnique(0)->getPass(0)->setLightingEnabled(false);

    // Create background rectangle covering the whole screen
    rect = new Rectangle2D(true);
    rect->setCorners(-1.0, 1.0, 1.0, -1.0);
    rect->setMaterial(BackGroundMaterial);

    // Render the background before everything else
    rect->setRenderQueueGroup(Ogre::RENDER_QUEUE_BACKGROUND);

    // Use infinite AAB to always stay visible
    aabInf.setInfinite();
    rect->setBoundingBox(aabInf);



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

    // set up material
    MaterialSetup();

    // create player
    playerOBJ->Setup(scnMgr, Vector3(0, 0, 0), Vector3(0.1f, 0.1f, 0.1f), PlayerMaterial);
    //playerOBJ->PlayerNode->roll(Degree(-90));
   
    // create background
    backgroundOBJ->Setup(scnMgr, Vector3(0, 0, 0), Vector3(15, 10, 1));
    backgroundOBJ->BackgroundNode->attachObject(rect);


    // create frame listener
    createFrameListener();



    // // ! [cameramove]
    camNode->setPosition(0, 47, 222);
    // // ! [cameramove]

    ////! [entity4]
    //Entity* ogreEntity4 = scnMgr->createEntity(scnMgr->PT_CUBE);
    //ogreNode4 = scnMgr->getRootSceneNode()->createChildSceneNode();
    //ogreNode4->setPosition(0, -10, 0);
    //ogreNode4->setScale(0.2f, 0.05f, 0.0f);
    //ogreNode4->roll(Degree(0));
    //ogreNode4->attachObject(ogreEntity4);
    ////! [entity4]




    scnMgr->showBoundingBoxes(true);


}




bool Game::keyPressed(const KeyboardEvent& evt)
{


    if (evt.keysym.sym == 'a')
    {
        FrameLsnr->PlayerTranslate = Vector3(-10, 0, 0);
    }

    if (evt.keysym.sym == 'd')
    {
        FrameLsnr->PlayerTranslate = Vector3(10, 0, 0);
    }


    switch (evt.keysym.sym)
    {
    case SDLK_ESCAPE:
        getRoot()->queueEndRendering();
        break;
    case 'w':
        FrameLsnr->PlayerTranslate = Vector3(0, 10, 0);
        break;
    case 'q':
        camNode->setPosition(camNode->getPosition() + Vector3(0, 0, 10));
        break;
    case 'e' :
        camNode->setPosition(camNode->getPosition() - Vector3(0, 0, 10));

        break;
    default:
        break;
    }








    return true;
}

bool Game::keyReleased(const KeyboardEvent& evt)
{

    if (evt.keysym.sym == 'a')
    {
        FrameLsnr->PlayerTranslate = Vector3(0, 0, 0);

    }

    if (evt.keysym.sym == 'd')
    {
        FrameLsnr->PlayerTranslate = Vector3(0, 0, 0);

    }

    if (evt.keysym.sym == 'w')
    {
        FrameLsnr->PlayerTranslate = Vector3(0, 0, 0);

    }

    return true;
}

void Game::frameRendered(const FrameEvent& evt)
{
     
}

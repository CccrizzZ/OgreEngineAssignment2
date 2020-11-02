#pragma once

#include "Ogre.h"
#include "OgreApplicationContext.h"
#include "OgreInput.h"
#include "OgreRTShaderSystem.h"
#include <iostream>
#include "OgreTrays.h"
#include "Platform.h"
#include "Player.h"
#include "MyFrameListener.h"
#include "Background.h"

using namespace Ogre;
using namespace OgreBites;

class Game : public ApplicationContext, public InputListener
{
public:
    Game();
    virtual ~Game(){}




    // Core Methods
    void setup();
    void CoreSetup();
    void UISetup();
    void createFrameListener();
    
    
    bool keyPressed(const KeyboardEvent& evt);
    bool keyReleased(const KeyboardEvent& evt);

    void frameRendered(const FrameEvent& evt);
    




    // Core Object
    Root* root;
    SceneManager* scnMgr;
    Light* light;
    Camera* cam;
    SceneNode* lightNode;
    SceneNode* camNode;
    RTShader::ShaderGenerator* shadergen;
    MyFrameListener* FrameLsnr;


    // Game Object
    int score;
    Player* playerOBJ;
    SceneNode* ogreNode4;
    Background* backgroundOBJ;





    // UI
    TrayListener myTrayListener;
    Label* mInfoLabel;
    TrayManager* mTrayMgr;

    

};

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
#include "AManager.h"
#include "OgreAxisAlignedBox.h"
#include "OgreRectangle2D.h"



#include <string.h>

using namespace std;
using namespace audiere;
using namespace Ogre;
using namespace OgreBites;

class Game : public ApplicationContext, public InputListener
{
public:
    Game();
    ~Game();




    // Core Methods
    void setup();
    void CoreSetup();
    void UISetup();
    void MaterialSetup();
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

    // Material
    MaterialPtr BackGroundMaterial;
    MaterialPtr PlayerMaterial;


    Rectangle2D* rect;
    AxisAlignedBox aabInf;

    // UI
    TrayListener myTrayListener;
    Label* mInfoLabel;
    TrayManager* mTrayMgr;
    string scoreStr;
    StringVector names;
    

};

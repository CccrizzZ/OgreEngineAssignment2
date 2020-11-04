#pragma once
#include <string>
#include "audiere.h"
using namespace audiere;
using namespace std;


// notworking
class AManager
{
public:
    AManager() {
        // Name of the file
        string name = "./sounds/Jump.wav";

        // Create Object to open device 
        AudioDevicePtr device(OpenDevice());

        // Create Object to open the music file 
        OutputStreamPtr sound(OpenSound(device, name.c_str(), false));
        sound->play();
    };
    virtual ~AManager() {};


};



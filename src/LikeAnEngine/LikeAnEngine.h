/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  Student of system engineering, 7 semester
  at the EAFIT university from Colombia
  15 - June - 2010
*/
#ifndef LIKE_ENGINE_H_
#define LIKE_ENGINE_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <pthread.h>

#include "Utils/Camera.h"
#include "Conf/Loader.h"
#include "Utils/KeyboardManager.h"
#include "Objects/Sphere.h"
#include "Objects/Plane.h"
#include "Objects/Cube.h"
#include "Objects/Light.h"
#include "Objects/Model3DS.h"
#include "Utils/Math/CollitionsMath.h"

//Engine Objects
extern Loader *loader;
extern Camera *camera;
extern Sphere *sky;
extern Sphere *arraySpheres;
extern Plane *arrayPlanes;
extern Light *arrayLights;
extern Cube *arrayCubes;
extern Model3DS* arrayModels;
extern GLuint *arrayTexturesId;
extern KeyboardManager *keyboardManager;

//Perspective
extern   GLfloat perspectiveAngle, fAspect;

//Number of Engine Objects
extern   int numSpheres;//lenght of the arrayBalls
extern   int numPlanes;//Lenght of the arrayPlanes
extern   int numLights;//Lenght of the arrayLights
extern   int numCubes;//Lenght of the arrayCubes
extern   int numModels;//Lenght of the arrayModels

//DisplayList of the wold
//extern GLint worldDL;

//FPS
//extern GLint currTime;//the current number of miliseconds
//extern GLint pastTime;//The number of miliseconds since we last computed the frame rate
//extern GLint fps;//The number of frames per second




//FUNCTIONS

//Entry in a infinity loop, without this, the engine didnt work
void startEngineLoop();

/*
  init all values to start the engine
  int *argcp, char **argv are the parameters of the main func
*/
void initEngine(int argc, char **argv, const char* windowName);

/*
  Set the function that will be called every 10 msec, there
  you can ask for the key status
*/
void setKeyboardFunc(void(*func)());


/*
  The idle func is a func that is called infinite times (emule a while(true))
  The paramether is the pointer to the idle function that the user wants
*/
void setIdleFunc(void(*func)(void));

/**
  Add am aditional display function to draw other objects
  that where not defined in the objects conf file
*/
void setAditionalDisplayFunc(void(*func)(void));

/**
  Change the clear color of the window
*/
void setBackgroundColor(float color[4]);


/**
  Activate the fog efect in the world
  - fogColor: array with format RGBA
  - density: specifies the fog density used in both exponential
    fog equations. Only nonnegative densities are accepted.
  - z0: specifies the near distance used in the linear fog equation.
  - z1: specifies the far distance used in the linear fog equation.
*/
void activateFog(float fogColor[4], float density, float z0, float z1);

/**
  Deactivate the fog in the world
*/
void deactivateFog();

#endif

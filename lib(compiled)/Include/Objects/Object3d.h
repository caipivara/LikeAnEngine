//This make that if so much classes uses this header, it will be compiled only once

#ifndef _OBJECT3D_H_
#define _OBJECT3D_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include <time.h>

using namespace std;

const GLfloat NO_SHININESS =  0.0 ;
const GLfloat LOW_SHININESS =  5.0;
const GLfloat HIGH_SHININESS =  100.0;
const GLfloat GRAVITY = 0.098;
const GLfloat DELTA_FALL_TIME = 0.4;

/*
  This class is the interface to all the objects in the world
*/
class Object3d{

public:
 private:
};



#endif

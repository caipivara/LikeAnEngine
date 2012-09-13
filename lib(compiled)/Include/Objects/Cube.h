/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  15 - August - 2009
*/



#ifndef _CUBE_H_
#define _CUBE_H_

#include "Object3d.h"
#include "../Utils/Imageloader.h"
#include "../Utils/Math/MyStructs.h"
#include "Plane.h"

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>


/*
  This class represents a sphere with his movements
*/
class Cube{
 public:
  Cube();
  Cube(GLdouble x, GLdouble y, GLdouble z, GLfloat side);
  Cube(GLdouble x, GLdouble y, GLdouble z, GLfloat side, GLdouble r, GLdouble g, GLdouble b, GLdouble alpha);
  Cube(GLdouble x, GLdouble y, GLdouble z, GLfloat side, GLdouble r, GLdouble g, GLdouble b, GLdouble alpha, GLdouble ambiental[4], GLdouble diffuse[4], GLdouble specular[4]);

  void initValues();//Initialize each attribute with a predefined value
  void initArrays();

  void jump();

  void draw();

  void moveInX(bool positive);//Move the sphere + delta if positive, else move -delta
  void moveInY(bool positive);
  void moveInZ(bool positive);

  //Set _nextPosY to _posY 
  void actualizePos();

  //Set all Textures

  void setTextures(GLuint texGen);//Set all the faces with the texGen texture
  void setTextureUp(GLuint tex);//Set only up texture of the cube
  void setTextureDown(GLuint tex);
  void setTextureLeft(GLuint tex);
  void setTextureRight(GLuint tex);
  void setTextureFront(GLuint tex);
  void setTextureBack(GLuint tex);

  void setPosY(GLdouble pos);
  void setState(char state);
  void setColor(GLdouble r, GLdouble g, GLdouble b, GLdouble alpha);

  /*
    Gets the real face, with no translation position of the vertex
  */
  Plane* getRealUpFace();
  Plane* getRealDownFace();
  Plane* getRealLeftFace();
  Plane* getRealRightFace();
  Plane* getRealFrontFace();
  Plane* getRealBackFace();
  
  /*
    Gets a plane that represents the face but with 
    the vertex translated in _posX, _posY, _posZ
    diferent order or vertex becouse the collision detection
  */
  Plane* getUpFace();
  Plane* getDownFace();
  Plane* getLeftFace();
  Plane* getRightFace();
  Plane* getFrontFace();
  Plane* getBackFace();

  GLdouble getState();
  GLdouble getSide();
  GLdouble getPosX();
  GLdouble getPosY();
  GLdouble getNextPosY();
  GLdouble getPosZ();
  
 private:
  //Position and how much the ball moves
  GLdouble _posX, _posY, _posZ, _deltaPosX, _deltaPosY, _deltaPosZ;
  GLuint _tex[6];
 
  GLdouble _nextPosY;
  GLdouble _initPosY;

  GLfloat _matAmbient[4]; //Material of the ball of the ambiental light
  GLfloat _matDiffuse[4];//Material of the ball of the diffuse light
  GLfloat _matSpecular[4];//Material of the ball of the specular light
  GLfloat _side;//Size of the side of the cube

  //Phisics for the jump =====
  GLfloat _velocity;
  GLfloat _timeJump;
  GLfloat _angleParabolicMove;
  //=========================
  char _state;//If is ' ' is not-jumping, if is 'j' it is jumping, 'c' if it collide with something

  GLdouble _arrayV[72];//8 vertex (x,y,z) needed to form a cube
  GLfloat _arrayC[96];//Color of each vertex (r,g,b,alpha)
  GLfloat _arrayN[72];//Vector Normal for each vertex (x,y,z)
  GLfloat _arrayT[48];//Tex Coords for each face (x,y)
};

#endif 

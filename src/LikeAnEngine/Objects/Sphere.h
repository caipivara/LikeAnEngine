/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  14 - August - 2009
*/
#ifndef _SPHERE_H_
#define _SPHERE_H_


#include "Object3d.h"
#include "../Utils/Imageloader.h"
#include <string>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


/*
  This class represents a sphere with his movements
*/
class Sphere{
  
 public:
  Sphere();
  Sphere(GLdouble x, GLdouble y, GLdouble z, GLfloat rad);
  Sphere(GLdouble x, GLdouble y, GLdouble z, GLfloat rad, GLfloat r, GLfloat g, GLfloat b, GLfloat alpha );
  Sphere(GLdouble x, GLdouble y, GLdouble z, GLfloat rad, GLfloat r, GLfloat g, GLfloat b, GLfloat alpha ,GLfloat ambiental[4], GLfloat diffuse[4], GLfloat specular[4]);

  
  void initValues();//Initialize each attribute with a predefined value
  void initQuad(bool inside);
  
  void draw();
  
  

  void moveInX(bool positive);//Move the sphere + delta if positive, else move -delta
  void moveInY(bool positive);
  void moveInZ(bool positive);

  void roteInX(bool positive);//Rote the sphere + delta if positive, else move -delta
  void roteInY(bool positive);
  void roteInZ(bool positive);


  //Set _nextPosY to _posY 
  void actualizePos();

  //calculate each position of the sphere and store in _nextPosY in a jump
  void jump();
  void applyGravity();
  void manageJumpRotation();

  void setSlicesAndStacks(GLint slices, GLint stacks);
  void setTexture(GLuint tex);
  void setState(char state);

  void setPosY(GLdouble pos); 
  void setPos(GLdouble* pos); 

  void setScale(GLfloat s[3]);

  void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha);
  void setBlendingFactors(GLenum source,GLenum destination );

  void checkState(int value);
 
  char getState();
  GLfloat getRadius();
  GLdouble getPosX();
  GLdouble getPosY();
  GLdouble getNextPosY();
  GLdouble getPosZ();
  GLfloat* getArrayColor();
  
 private:
  //Position and how much the ball moves
  GLdouble _posX, _posY, _posZ, _deltaPosX, _deltaPosY, _deltaPosZ;
  GLdouble _rotX, _rotY, _rotZ, _deltaRotX, _deltaRotY, _deltaRotZ;

  GLdouble _initPosY;//position before each jump
  /*Next position of the sphere in time, to secure that will go through the collide object (draw through it)
    The Collition algorithm will ask for the next position of the sphere, not for the actual*/
  GLdouble _nextPosY;
  GLfloat _scaleX, _scaleY, _scaleZ;

  GLfloat _matAmbient[4]; //Material of the ball of the ambiental light
  GLfloat _matDiffuse[4];//Material of the ball of the diffuse light
  GLfloat _matSpecular[4];//Material of the ball of the specular light
  GLfloat _radius;
  GLfloat _arrayColor[4];//Color of the ball, RGBA
  GLint _slices, _stacks;//Quality of the sphere to draw

  //Phisics for the jump =====
  GLdouble _velocity;
  GLdouble _timeJump;
  GLdouble _angleParabolicMove;
  //=========================
  char _state;//If is ' ' is not-jumping, if is 'j' it is jumping, 'c' if it collide with something
  GLuint _texture;//Id for the texture for the Sphere
  GLUquadric *_quad;//The quad for the texture and gluSphere

  string _direction;


  //Blending and transparency=
  GLenum _sourceFactor, _destFactor;

  //==========================
};



#endif 

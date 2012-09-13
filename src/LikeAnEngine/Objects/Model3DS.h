/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  28 - August - 2009
*/




#ifndef _MODEL_3DS_H_
#define _MODEL_3DS_H_

#include "../Utils/Imageloader.h"
#include "../Utils/Math/MyStructs.h"
#include "../Conf/l3ds.h"
#include "Object3d.h"


#include <iostream>
#include <string>


/*#include <lib3ds.h>
#include <lib3ds/file.h>
#include <lib3ds/mesh.h>*/


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/*
  This class represents a plane
*/
class Model3DS{
 public:
  Model3DS(const char* fileName);
  Model3DS(const char* fileName,GLfloat ambiental[4],GLfloat diffuse[4],GLfloat specular[4], GLdouble pos[3],GLdouble deltaPos[3] );

  Model3DS();
  void draw();
  
  void initValues();//Initialize each attribute with a predefined values

  void moveInX(bool positive);//Move the plane + delta if positive, else move -delta
  void moveInY(bool positive);
  void moveInZ(bool positive);


  void setTexture(GLuint texture);
  
  void setPos(GLdouble x, GLdouble y, GLdouble z);
  void setPosX(GLdouble pos);
  void setPosY(GLdouble pos);
  void setPosZ(GLdouble pos);
  void setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha);

  GLfloat* getColor();

  GLdouble getPosX();
  GLdouble getPosY();
  GLdouble getPosZ();

  
 private:
  GLdouble _posX, _posY, _posZ, _deltaPosX, _deltaPosY, _deltaPosZ;//Position and how much the ball moves
  GLdouble _rotX, _rotY, _rotZ;
  GLfloat _arrayColor[4];//Color of the plane, RGBA
  
   GLfloat _matAmbient[4]; //Material of the ball of the ambiental light
  GLfloat _matDiffuse[4];//Material of the ball of the diffuse light
  GLfloat _matSpecular[4];//Material of the ball of the specular light
  
  GLuint _texture;//ID for the texture of the planed
  GLfloat *_arrayC;//Color of each vertex (r,g,b,alpha)
 
  /*
  //Blending and transparency=
  GLenum _sourceFactor, _destFactor;
  //==========================
  */
  /*GLdouble *_arrayV;//4 vertex (x,y,z)
  GLdouble *_arrayOrden;
  GLfloat _arrayC[16];//Color of each vertex (r,g,b,alpha)
  GLfloat _arrayN[12];//Vector Normal for each vertex (x,y,z)
  GLfloat _arrayT[8];//Tex Coords for object (x,y)
  */
 
  LMesh **_arrayMesh;
  GLuint _numMesh;
};

#endif 

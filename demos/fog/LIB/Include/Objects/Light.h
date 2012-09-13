/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  14 - August - 2009
*/


#ifndef _LIGHTS_H_
#define _LIGHTS_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

/*
  A light is a object that emit light for each type (ambiental, specular, diffuse) in all directions
  and has a position
 */
class Light{
 public:
  Light();
  Light(GLfloat p[4]);//GLfloat x, GLfloat y, GLfloat z);
  Light(GLfloat p[4], GLfloat rad);
  Light(GLfloat ambiental[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat p[4]);

  void initValues();//Initialize each attribute with a predefined value
  void enableGLLight(int nLight);//Says to Opengl what light enable based on nLight  
  
  bool intersect();
  void draw();//Reposition the light if the light wre moved and draw a sphere that represent it

  void moveInX(bool positive);//Move the light + delta if positive, else move -delta
  void moveInY(bool positive);
  void moveInZ(bool positive);

  void setDrawLight(bool draw);
  void setAttenuationFacts(GLfloat c, GLfloat l, GLfloat q);

  GLfloat getRadius();
  GLfloat getPosX();
  GLfloat getPosY();
  GLfloat getPosZ();
  
  
 private:
  GLfloat _deltaPosX, _deltaPosY, _deltaPosZ;//How much the light moves in each 
  bool _drawLight;//Says if the draw func will draw a sphere representing the light
  GLfloat _arrayAmbient[4]; //Ambiental light
  GLfloat _arrayDiffuse[4];//Diffuse light
  GLfloat _arraySpecular[4];//Specular light
  GLfloat _arrayPosition[4];//Position of the light
  
  GLfloat _radius;//Radius of the sphere that represents the light in the escene
  GLfloat _r,_g,_b;//Color of the ball
  GLfloat _attC,_attL,_attQ;//Values to the attenuation-> Constant, Linear, Quadratic
  
  GLenum _glLight;//The GL_LIGHT(i) that represents this light
};

#endif 

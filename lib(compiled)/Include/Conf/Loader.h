/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  27 - September - 2009
*/


#ifndef LOADER_H_
#define LOADER_H_

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

#include "../Utils/Camera.h"
#include "../Objects/Sphere.h"
#include "../Objects/Plane.h"
#include "../Objects/Cube.h"
#include "../Objects/Light.h"
#include "../Objects/Model3DS.h"


#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

const string CARPET_FILES = "./LikeAnEngine/Conf/";
const string CARPET_TEXTURES = "Textures/";
const string PATH_FILE = CARPET_FILES + "world.txt";
const string PATH_MODELS = CARPET_FILES+"Models/";


struct Model{
  string name;//Name of file
  GLfloat ma[4];//Materials
  GLfloat md[4];
  GLfloat ms[4];
  GLdouble p[3];//Position
  GLdouble deltaP[3];
};


/*
  This class load the data from a file in PATH_FILE
*/
class Loader{
 public:
  Loader();
  void load();
  void loadModels();
  void manageLine(string line);
 
  void initTextures();

  void addSphere(Sphere* s, GLuint tex);
  void addPlane(Plane* p, GLuint tex, GLdouble x, GLdouble y, GLdouble z, GLfloat arrayC[8]);
  void addCube(Cube* c, GLuint tex);
  void addLight(Light* l, GLfloat attC, GLfloat attL, GLfloat attQ);

  Camera* getCamera();
  Sphere* getSpheres();
  Plane* getPlanes();
  Cube* getCubes();
  Light* getLights();
  GLuint* getTextures();
  Model3DS* getModels();

  GLint getNumberS();
  GLint getNumberP();
  GLint getNumberC();
  GLint getNumberL();
  GLint getNumberM();
  
  
 private:
  Camera* _camera;
  Sphere* _arraySpheres;
  Plane* _arrayPlanes;
  Cube* _arrayCubes;
  Light* _arrayLights;

  Model3DS* _arrayModels;
  Model* _arrayTempModels;

  GLuint* _arrayTexturesId;
  string* _arrayNameTextures;
  Image* _arrayImages;


  //Number of spheres, planes, cubes, lights, textures, models
  GLint ns,np,nc,nl,nt, nm;
};

#endif 

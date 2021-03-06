
/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  28 - August - 2009
*/

#include "Model3DS.h"

//=============================Constructors=====================

Model3DS::Model3DS(){}
#include <iostream>
Model3DS::Model3DS(const char* fileName){

  L3DS *loader = new L3DS(fileName);

  _numMesh = loader->GetMeshCount();
  _arrayMesh = new LMesh*[_numMesh];


  for(unsigned int i = 0; i < _numMesh; i++){
    _arrayMesh[i] = &loader->GetMesh(i);
    _arrayMesh[i]->Optimize(oFull);
  }


  initValues();


}

Model3DS::Model3DS(const char* fileName,GLfloat ambiental[4],GLfloat diffuse[4],GLfloat specular[4], GLdouble pos[3],GLdouble deltaPos[3] ){
  L3DS *loader = new L3DS(fileName);

  _numMesh = loader->GetMeshCount();
  _arrayMesh = new LMesh*[_numMesh];


  for(unsigned int i = 0; i < _numMesh; i++){
    _arrayMesh[i] = &loader->GetMesh(i);
    _arrayMesh[i]->Optimize(oFull);
  }

  initValues();

  _posX = pos[0] ,_posZ = pos[2], _deltaPosX = deltaPos[0], _deltaPosY = deltaPos[1], _deltaPosZ = deltaPos[2];
  setPosY(pos[1]);

  _matAmbient[0] = ambiental[0] ,_matAmbient[1] = ambiental[1],_matAmbient[2] = ambiental[2], _matAmbient[3] = ambiental[3];
  _matDiffuse[0] = diffuse[0] ,_matDiffuse[1] = diffuse[1],_matDiffuse[2] = diffuse[2], _matDiffuse[3] = diffuse[3];
  _matSpecular[0] = specular[0] ,_matSpecular[1] = specular[1] ,_matSpecular[2] = specular[2] , _matSpecular[3] = specular[3];
}

void Model3DS::draw(){
  glPushMatrix();

  //glEnable(GL_TEXTURE_2D);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  //glEnableClientState(GL_COLOR_ARRAY);

     for (uint i= 0; i < _numMesh; i++)
       {
	 LMesh *mesh = _arrayMesh[i];
	 /*GLfloat color[3*mesh->GetVertexCount()];

	 for(int i = 0; i < mesh->GetVertexCount(); i+=3){
	   color[i] = mesh->GetMaterial(0);
	   color[i+1] = mesh->GetMaterial(1);
	   color[i+2] = mesh->GetMaterial(2);
	   //std::cout << color[i]<< ' '<<color[i+1]<< ' '<<color[i+2]<< ' '<<mesh->GetMaterialCount()<<std::endl;
	   }*/


	 glVertexPointer(4, GL_FLOAT, 0, &mesh->GetVertex(0));
	 glNormalPointer(GL_FLOAT, 0, &mesh->GetNormal(0));

	 glMaterialfv (GL_FRONT, GL_AMBIENT, _matAmbient);
	 glMaterialfv (GL_FRONT, GL_DIFFUSE, _matDiffuse);
	 glMaterialfv (GL_FRONT, GL_SPECULAR, _matSpecular);
	 glMaterialf (GL_FRONT, GL_SHININESS, HIGH_SHININESS);


	 //glColorPointer(3, GL_FLOAT, 0, &color);//&mesh->GetBinormal(0));

	 glTranslatef(_posX, _posY, _posZ);
	 glRotatef(_rotX, 1.0, 0.0, 0.0);
	 glRotatef(_rotY, 0.0, 1.0, 0.0);
	 glRotatef(_rotZ, 0.0, 0.0, 1.0);
	 glColor4f(_arrayColor[0],_arrayColor[1],_arrayColor[2],_arrayColor[3]);
	 //glBindTexture(GL_TEXTURE_2D, _texture);


	 glDrawElements(GL_TRIANGLES, mesh->GetTriangleCount()*3,
	   GL_UNSIGNED_SHORT, &mesh->GetTriangle(0));
       }

     //glDisable(GL_TEXTURE_2D);
  glDisableClientState(GL_VERTEX_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  //glDisableClientState(GL_COLOR_ARRAY);
  glPopMatrix();
}


void Model3DS::initValues(){
  _posX = 0.0, _posY = 0.0, _posZ = 0.0, _deltaPosX = 1.0, _deltaPosY = 1.0, _deltaPosZ = 1.0;
  _rotX = -90.0, _rotY = 0.0; _rotZ = 0.0;

  _matAmbient[0] = 0.5 ,_matAmbient[1] = 0.0,_matAmbient[2] = 0.5, _matAmbient[3] = 1.0;
  _matDiffuse[0] = 0.0 ,_matDiffuse[1] = 1.0,_matDiffuse[2] = 1.0, _matDiffuse[3] = 1.0;
  _matSpecular[0] = 1.0 ,_matSpecular[1] = 0.8,_matSpecular[2] = 0.3, _matSpecular[3] = 1.0;
  _arrayColor[0] = 0.5,_arrayColor[1] = 0.5,_arrayColor[2] = 0.5,_arrayColor[3] = 1.0;
}


//============================================================

void Model3DS::moveInX(bool positive){
  if(positive)_posX += _deltaPosX;
  else _posX -= _deltaPosX;
}

void Model3DS::moveInY(bool positive){
  if(positive)_posY += _deltaPosY;
  else _posY -= _deltaPosY;
}

void Model3DS::moveInZ(bool positive){
  if(positive)_posZ += _deltaPosZ;
  else _posZ -= _deltaPosZ;
}



//=====================================Getters - Setters ========================

void Model3DS::setTexture(GLuint texture){_texture = texture;}

void Model3DS::setPos(GLdouble x, GLdouble y, GLdouble z)
{
  setPosX(x);
  setPosY(y);
  setPosZ(z);
}
void Model3DS::setPosX(GLdouble pos){ _posX = pos;}
void Model3DS::setPosY(GLdouble pos){ _posY = pos;}
void Model3DS::setPosZ(GLdouble pos){ _posZ = pos;}

void Model3DS::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha){
  _arrayColor[0] = r, _arrayColor[1] = g, _arrayColor[2] = b,_arrayColor[3] = alpha;
}

GLfloat* Model3DS::getColor(){return _arrayColor;}

GLdouble Model3DS::getPosX(){return _posX;}
GLdouble Model3DS::getPosY(){return _posY;}
GLdouble Model3DS::getPosZ(){return _posZ;}

//================================================================================

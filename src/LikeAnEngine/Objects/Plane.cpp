
/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  28 - August - 2009
*/

#include "Plane.h"

//=============================Constructors=====================
Plane::Plane(){
  initValues();
  initArrays(_arrayV);
  calcNormal();
  calcD();
  setColor(1.0, 1.0, 1.0, 1.0);
}

Plane::Plane(GLdouble arrayV[12]){
  initValues();
  initArrays(arrayV);
  calcNormal();
  calcD();
  setColor(1.0, 1.0, 1.0, 1.0);
}

Plane::Plane(GLdouble arrayV[12], GLfloat r, GLfloat g, GLfloat b, GLfloat alpha){
  initValues();
  initArrays(arrayV);
  calcNormal();
  calcD();
  setColor(r, g, b, alpha);
}

Plane::Plane(GLdouble arrayV[12], GLfloat r, GLfloat g, GLfloat b, GLfloat alpha, GLdouble amb[4],GLdouble dif[4],GLdouble spec[4]){
  initValues();
  initArrays(arrayV);
  calcNormal();
  calcD();
  setColor(r, g, b, alpha);

  _matAmbient[0] = amb[0] ,_matAmbient[1] = amb[1],_matAmbient[2] = amb[2], _matAmbient[3] = amb[3];
  _matDiffuse[0] = dif[0] ,_matDiffuse[1] = dif[1],_matDiffuse[2] = dif[2], _matDiffuse[3] = dif[3];
  _matSpecular[0] = spec[0] ,_matSpecular[1] = spec[1],_matSpecular[2] = spec[2], _matSpecular[3] = spec[3];

}

void Plane::initValues(){
  _posX = 0.0, _posY = 0.0, _posZ = 0.0, _deltaPosX = 1.0, _deltaPosY = 1.0, _deltaPosZ = 1.0;

  _sourceFactor = GL_SRC_ALPHA, _destFactor = GL_ONE_MINUS_SRC_ALPHA;

  _matAmbient[0] = 0.5 ,_matAmbient[1] = 0.0,_matAmbient[2] = 0.5, _matAmbient[3] = 1.0;
  _matDiffuse[0] = 0.0 ,_matDiffuse[1] = 1.0,_matDiffuse[2] = 1.0, _matDiffuse[3] = 1.0;
  _matSpecular[0] = 1.0 ,_matSpecular[1] = 0.8,_matSpecular[2] = 0.3, _matSpecular[3] = 1.0;

  _arrayV[0] = 50.0; _arrayV[1] = 0.0;  _arrayV[2] = -50.0;
  _arrayV[3] = 50.0; _arrayV[4] = 0.0;  _arrayV[5] = 50.0;
  _arrayV[6] = -50.0; _arrayV[7] = 0.0;  _arrayV[8] = 50.0;
  _arrayV[9] = -50.0; _arrayV[10] = 0.0; _arrayV[11] = -50.0;

}

void Plane::calcNormal(){
  MyVector3d v1(_arrayV[3] - _arrayV[0], _arrayV[4] - _arrayV[1], _arrayV[5] - _arrayV[2]);
  MyVector3d v2(_arrayV[9] - _arrayV[0], _arrayV[10] - _arrayV[1], _arrayV[11] - _arrayV[2]);
  _normal = v1.cross(v2);
  _normal.normalize();
  for(int i = 0; i < 10; i+= 3){
    _arrayN[i] = _normal.getX(); _arrayN[i+1] = _normal.getY(); _arrayN[i+2] = _normal.getZ();
  }
  cout << "  "<<endl;
}

void Plane::calcD(){
  _D = _normal.getX()*_posX + _normal.getY()*_posY + _normal.getZ()*_posZ;
  _D = _D;
}

void Plane::initArrays(GLdouble arrayV[12]){
  _arrayV[0] = arrayV[0]; _arrayV[1] = arrayV[1];  _arrayV[2] = arrayV[2];
  _arrayV[3] = arrayV[3]; _arrayV[4] = arrayV[4];  _arrayV[5] = arrayV[5];
  _arrayV[6] = arrayV[6]; _arrayV[7] = arrayV[7];  _arrayV[8] = arrayV[8];
  _arrayV[9] = arrayV[9]; _arrayV[10] = arrayV[10]; _arrayV[11] = arrayV[11];

  _arrayT[0] = 0.0; _arrayT[1] = 0.0;
  _arrayT[2] = 0.0; _arrayT[3] = 0.5;
  _arrayT[4] = 0.5; _arrayT[5] = 0.5;
  _arrayT[6] = 0.5; _arrayT[7] = 0.0;
}

//============================================================

void Plane::draw(){
  glPushMatrix();

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);

    glEnable(GL_BLEND);
    glBlendFunc(_sourceFactor, _destFactor);

    glVertexPointer(3, GL_DOUBLE, 0, _arrayV);
    glColorPointer(4, GL_FLOAT, 0, _arrayC);
    glNormalPointer(GL_FLOAT, 0, _arrayN);
    glTexCoordPointer(2, GL_FLOAT, 0, _arrayT);

    glEnable(GL_TEXTURE_2D);

        glMaterialfv (GL_FRONT, GL_AMBIENT, _matAmbient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, _matDiffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, _matSpecular);
	glMaterialf (GL_FRONT, GL_SHININESS, HIGH_SHININESS);

	glTranslatef(_posX, _posY, _posZ);

	glBindTexture(GL_TEXTURE_2D, _texture);

	//glPolygonMode(GL_FRONT, GL_FILL);
	//glPolygonMode(GL_FRONT, GL_LINE);
	//glPolygonMode(GL_BACK, GL_LINE);

	glDrawArrays( GL_QUADS, 0, 4 );


    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

  glPopMatrix();
}

void Plane::moveInX(bool positive){
  if(positive)_posX += _deltaPosX;
  else _posX -= _deltaPosX;
}

void Plane::moveInY(bool positive){
  if(positive)_posY += _deltaPosY;
  else _posY -= _deltaPosY;
}

void Plane::moveInZ(bool positive){
  if(positive)_posZ += _deltaPosZ;
  else _posZ -= _deltaPosZ;
}



//=====================================Getters - Setters ========================

void Plane::setTextureCoord(GLfloat arrayC[8]){
  _arrayT[0] = arrayC[0]; _arrayT[1] = arrayC[1];
  _arrayT[2] = arrayC[2]; _arrayT[3] = arrayC[3];
  _arrayT[4] = arrayC[4]; _arrayT[5] = arrayC[5];
  _arrayT[6] = arrayC[6]; _arrayT[7] = arrayC[7];
}

void Plane::setTexture(GLuint texture){_texture = texture;}

void Plane::setPos(GLdouble x, GLdouble y, GLdouble z)
{
  setPosX(x);
  setPosY(y);
  setPosZ(z);
}
void Plane::setPosX(GLdouble pos){ _posX = pos;}
void Plane::setPosY(GLdouble pos){ _posY = pos;}
void Plane::setPosZ(GLdouble pos){ _posZ = pos;}

void Plane::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha){
  _arrayColor[0] = r, _arrayColor[1] = g, _arrayColor[2] = b,_arrayColor[3] = alpha;
  for(int i = 0; i< 25; i+= 4){
    _arrayC[i] = r; _arrayC[i+1] = g; _arrayC[i+2] = b; _arrayC[i+3] = alpha;
  }

}
void Plane::setBlendingFactors(GLenum source,GLenum destination ){
  _sourceFactor = source, _destFactor = destination;
}

GLfloat* Plane::getColor(){return _arrayColor;}

GLdouble Plane::getPosX(){return _posX;}
GLdouble Plane::getPosY(){return _posY;}
GLdouble Plane::getPosZ(){return _posZ;}

MyPoint3d* Plane::getRealVertex1(){return new MyPoint3d(_arrayV[0], _arrayV[1], _arrayV[2]);}
MyPoint3d* Plane::getRealVertex2(){return new MyPoint3d(_arrayV[3], _arrayV[4], _arrayV[5]);}
MyPoint3d* Plane::getRealVertex3(){return new MyPoint3d(_arrayV[6], _arrayV[7], _arrayV[8]);}
MyPoint3d* Plane::getRealVertex4(){return new MyPoint3d(_arrayV[9], _arrayV[10], _arrayV[11]);}

MyPoint3d* Plane::getVertex1(){
  return new MyPoint3d(_arrayV[0]+_posX, _arrayV[1]+_posY, _arrayV[2]+_posZ);
}
MyPoint3d* Plane::getVertex2(){
  return new MyPoint3d(_arrayV[3]+_posX, _arrayV[4]+_posY, _arrayV[5]+_posZ);
}
MyPoint3d* Plane::getVertex3(){
  return new MyPoint3d(_arrayV[6]+_posX, _arrayV[7]+_posY, _arrayV[8]+_posZ);
}
MyPoint3d* Plane::getVertex4(){
  return new MyPoint3d(_arrayV[9]+_posX, _arrayV[10]+_posY, _arrayV[11]+_posZ);
}

GLfloat Plane::getD(){return _D;}
MyVector3d* Plane::getNormal(){return &_normal;}

//================================================================================

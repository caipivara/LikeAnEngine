/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  14 - August - 2009
*/

#include "Sphere.h"

//=============================Constructors=====================
Sphere::Sphere(){
  initValues();
}

Sphere::Sphere(GLdouble x, GLdouble y, GLdouble z, GLfloat rad){
  initValues();//Init predef values
  //We Give the new values
  _posX = x, _posZ = z;
  setPosY(y);

  _initPosY = _posY;
  _radius = rad;
}

Sphere::Sphere(GLdouble x, GLdouble y, GLdouble z, GLfloat rad, GLfloat r, GLfloat g, GLfloat b, GLfloat alpha){
  initValues();//Init predef values
  //We Give the new values
  _posX = x, _posZ = z;
  setPosY(y);
  _radius = rad;
  _arrayColor[0] = r, _arrayColor[1] = g, _arrayColor[2] = b,_arrayColor[3] = alpha;
}

Sphere::Sphere(GLdouble x, GLdouble y, GLdouble z, GLfloat rad, GLfloat r, GLfloat g, GLfloat b,GLfloat alpha, GLfloat ambiental[4], GLfloat diffuse[4], GLfloat specular[4]){
  initValues();//Init predef values
  //We Give the new values
  _posX = x, _posZ = z;
  setPosY(y);
  _radius = rad;

  _arrayColor[0] = r, _arrayColor[1] = g, _arrayColor[2] = b,_arrayColor[3] = alpha;

  _matAmbient[0] = ambiental[0] ,_matAmbient[1] = ambiental[1],_matAmbient[2] = ambiental[2], _matAmbient[3] = ambiental[3];
  _matDiffuse[0] = diffuse[0] ,_matDiffuse[1] = diffuse[1],_matDiffuse[2] = diffuse[2], _matDiffuse[3] = diffuse[3];
  _matSpecular[0] = specular[0] ,_matSpecular[1] = specular[1] ,_matSpecular[2] = specular[2] , _matSpecular[3] = specular[3];
}

void Sphere::initValues(){
  _posX = 0.0, _posZ = 0.0, _deltaPosX = 0.5, _deltaPosY = 0.5, _deltaPosZ = 0.5;
  _rotX = 0.0, _rotY = 0.0, _rotZ = 0.0, _deltaRotX = 5.0, _deltaRotY = 5.0, _deltaRotZ = 5.0;
  _scaleX = 1.0;  _scaleY = 1.0;  _scaleZ = 1.0;

  setPosY(0.0);

  _radius = 10.0;

  _arrayColor[0] = 0.0, _arrayColor[1] = 0.5, _arrayColor[2] = 0.8, _arrayColor[3] = 1.0;

  //_sourceFactor = GL_SRC_ALPHA, _destFactor = GL_ONE_MINUS_SRC_ALPHA;
  _sourceFactor = GL_SRC_ALPHA, _destFactor = GL_ONE_MINUS_SRC_ALPHA;

  _slices = 20, _stacks = 20;


  _matAmbient[0] = 1.0 ,_matAmbient[1] = 1.0,_matAmbient[2] = 1.0, _matAmbient[3] = 1.0;
  _matDiffuse[0] = 1.0 ,_matDiffuse[1] = 1.0,_matDiffuse[2] = 1.0, _matDiffuse[3] = 1.0;
  _matSpecular[0] = 1.0 ,_matSpecular[1] = 1.0,_matSpecular[2] = 1.0, _matSpecular[3] = 1.0;

  _velocity = -2.0;
  _timeJump = 0.0;
  _angleParabolicMove = 30.0;

  _state = ' ';

  _direction = "r";

  initQuad(0);

  //glutTimerFunc(DELTA_FALL_TIME, checkState, 1);
}

void Sphere::initQuad(bool inside){
  _quad = gluNewQuadric();
  gluQuadricTexture(_quad, GL_TRUE);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);			// Set Up Sphere Mapping
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

  //gluQuadricDrawStyle(_quad,GLU_POINT);

  if(inside)gluQuadricOrientation(_quad,GLU_INSIDE);
  else gluQuadricOrientation(_quad,GLU_OUTSIDE);
}

//============================================================

void Sphere::draw(){
  glPushMatrix();

  glEnable(GL_TEXTURE_2D);

  glEnable(GL_BLEND);
  glBlendFunc(_sourceFactor, _destFactor);

  glMaterialfv (GL_FRONT, GL_AMBIENT, _matAmbient);
  glMaterialfv (GL_FRONT, GL_DIFFUSE, _matDiffuse);
  glMaterialfv (GL_FRONT, GL_SPECULAR, _matSpecular);
  glMaterialf (GL_FRONT, GL_SHININESS, HIGH_SHININESS);

  glColor4f(_arrayColor[0], _arrayColor[1], _arrayColor[2], _arrayColor[3]);


  glTranslatef(_posX, _posY, _posZ);


  glRotatef(_rotZ, 0.0, 0.0, 1.0);
  glRotatef(_rotX, 1.0, 0.0, 0.0);
  glRotatef(_rotY, 0.0, 1.0, 0.0);

  glScalef(_scaleX,_scaleY,_scaleZ);

  glBindTexture(GL_TEXTURE_2D, _texture);

  //glPolygonMode(GL_FRONT, GL_FILL);
  //glPolygonMode(GL_BACK, GL_FILL);

  gluSphere(_quad, _radius,_slices, _stacks);

  glDisable(GL_BLEND);

  glDisable(GL_TEXTURE_2D);
  glPopMatrix();
}



void Sphere::checkState(int value){
  if(getState() == 'j'){
    jump();
  }
}


void Sphere::moveInX(bool positive){
  if(positive){
    _direction = "r";
    _posX += _deltaPosX;
    roteInZ(false);
  }
  else {
    _direction = "l";
    _posX -= _deltaPosX;
    roteInZ(true);
  }
}

void Sphere::moveInY(bool positive){
  if(positive){
    _posY += _deltaPosY;
    roteInZ(false);
  }
  else{
    _posY -= _deltaPosY;
    roteInZ(true);
  }
  _initPosY = _posY;
  _nextPosY = _posY;
}

void Sphere::moveInZ(bool positive){
  if(positive){
    _direction = "u";
    _posZ += _deltaPosZ;
    roteInX(true);
  }
  else{
    _direction = "d";
    _posZ -= _deltaPosZ;
    roteInX(false);
  }
}

void Sphere::roteInX(bool positive){
  if(positive){
    _rotX += _deltaRotX;
  }
  else {
    _rotX -= _deltaRotX;
  }

  if(_rotX > 360.0 || _rotX < -360){
    _rotX = 0;
  }
}

void Sphere::roteInY(bool positive){
  if(positive){
    _rotY += _deltaRotY;
  }
  else{
    _rotY -= _deltaRotY;
  }
  if(_rotY > 360.0 || _rotY < -360) _rotY = 0;
}

void Sphere::roteInZ(bool positive){
  if(positive){
    _rotZ += _deltaRotZ;
  }
  else{
    _rotZ -= _deltaRotZ;
  }
  if(_rotZ > 360.0 || _rotZ < -360)_rotZ = 0;
}

void Sphere::actualizePos(){
  _posY = _nextPosY;
}

void Sphere::jump(){
    GLdouble time = clock();

    _nextPosY = _velocity*(sin(_angleParabolicMove))*_timeJump  +_initPosY;

    applyGravity();

    manageJumpRotation();
    //----------------"delay" 0.01 seg--------------------
    while ((clock() - time) < 0.01*CLOCKS_PER_SEC){}
    //----------------------------------------------------

}

void Sphere::applyGravity(){
  _nextPosY -= (GRAVITY*_timeJump*_timeJump)/2.0;
  _timeJump += DELTA_FALL_TIME;
}

void Sphere::manageJumpRotation(){
  if(_direction == "r") roteInZ(false);
  else if(_direction == "l") roteInZ(true);
  else if(_direction == "u") roteInX(true);
  else if(_direction == "d") roteInX(false);
}


void Sphere::setSlicesAndStacks(GLint slices, GLint stacks){
  _slices = slices;
  _stacks = stacks;
}

void Sphere::setTexture(GLuint tex){_texture = tex;}

void Sphere::setState(char state){
  _state = state;
  if(_state == ' '){
    _timeJump = 0.0;
  }
  if(_state == 'c'){
//	if(_velocity > 0){ _posY -= 1.0;}
 //   setPosY(_posY);
    _timeJump = 0.0;
 //   _velocity *= -1;
 //   _state = 'j';
  }
}

void Sphere::setPosY(GLdouble pos){
  _posY = pos;
  _initPosY = pos;
  _nextPosY = pos;
}


void Sphere::setPos(GLdouble pos[3]){
  _posX = pos[0];
  _posZ = pos[2];
  setPosY((GLdouble)pos[1]);
}

void Sphere::setScale(GLfloat s[3]){
  _scaleX = s[0];  _scaleY = s[1];  _scaleZ = s[2];
}
void Sphere::setColor(GLfloat r, GLfloat g, GLfloat b, GLfloat alpha){
  _arrayColor[0] = r, _arrayColor[1] = g, _arrayColor[2] = b,_arrayColor[3] = alpha;
}

void Sphere::setBlendingFactors(GLenum source,GLenum destination ){
  _sourceFactor = source, _destFactor = destination;
}

GLfloat* Sphere::getArrayColor(){return _arrayColor;}
char Sphere::getState(){return _state;}
GLfloat Sphere::getRadius(){return _radius;}
GLdouble Sphere::getPosX(){return _posX;}
GLdouble Sphere::getPosY(){return _posY;}
GLdouble Sphere::getNextPosY(){return _nextPosY;}
GLdouble Sphere::getPosZ(){return _posZ;}




//Thanks to http://www.lighthouse3d.com/opengl/glut/index.php?
/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  24 - September - 2009
*/

#include "Camera.h"

//Constructors ----------------------------------------------------------
Camera::Camera(){
  initValues();
  calcLineSight();
  setLookAt();
}

Camera::Camera(GLdouble posX, GLdouble posY, GLdouble posZ){
  initValues();  
  _pX=posX,_pY=posY,_pZ=posZ;
  calcLineSight();
  setLookAt();
}

Camera::Camera(GLdouble posX, GLdouble posY, GLdouble posZ,GLdouble deltaAngleCamTheta, GLdouble deltaAngleCamBeta,GLdouble deltaMoveCam,GLdouble theta, GLdouble beta){
  initValues();
  _pX=posX,_pY=posY,_pZ=posZ;
  _deltaTheta = deltaAngleCamTheta, _deltaBeta = deltaAngleCamBeta;
  _deltaMove = deltaMoveCam;
  _theta=theta, _beta= beta;//Finded experimental

  calcLineSight();
  setLookAt();
}

void Camera::initValues(){
  _pX=0.0f, _pY=20.0f, _pZ=70.0f;  
  _theta=42.4, _beta= 45.6;//Finded experimental
  _deltaTheta = 0.02, _deltaBeta = 0.02;
  _deltaMove = 5.0;
  _r = 0.2;
  _uvX = 0.0, _uvY = 1.0, _uvZ = 0.0;
}
//--------------------------------------------------------------------------



void Camera::setDeltaMoveCam(GLdouble deltaMoveCam){
  _deltaMove = deltaMoveCam;
}

void Camera::setDeltaAngleCam(GLfloat deltaAngleCamTheta, GLfloat deltaAngleCamBeta){
  _deltaTheta = deltaAngleCamTheta;
  _deltaBeta = deltaAngleCamBeta;
}

void Camera::setPos(GLdouble posX, GLdouble posY, GLdouble posZ){
   _pX=posX,_pY=posY,_pZ=posZ;
   setLookAt();
}

GLdouble* Camera::getLookAt(){
  GLdouble *a = new GLdouble[3]; 
  a[0]= _pX + (_deltaMove*50.0)*_lX*_r; a[1]= _pY + (_deltaMove*50.0)*_lY*_r; a[2]= _pZ + (_deltaMove*50.0)*_lZ*_r;
  return a;
}

void Camera::orientAngleCam(bool changeBeta,  bool positiveBeta,bool changeTheta, bool positiveTheta) {
  if(changeBeta){
    if( positiveBeta) _beta += _deltaBeta;//Add the delta
    else _beta -= _deltaBeta;//Subtract the delta
  }
  if(changeTheta){
    if(positiveTheta) _theta += _deltaTheta;
    else _theta -= _deltaTheta;
  }
  calcLineSight();
  setLookAt();
}


void Camera::moveCamFront(bool toFront) {
  
  if(toFront){
    _pX += _deltaMove*_lX*_r;
    _pZ += _deltaMove*_lZ*_r;
    _pY += _deltaMove*_lY*_r;
  }
  else{
    _pX -= _deltaMove*_lX*_r;
    _pZ -= _deltaMove*_lZ*_r;
    _pY -= _deltaMove*_lY*_r; 
  }
  
  setLookAt();
}

void Camera::moveCamUp(bool up) {
  
  if(up){
    _pY += _deltaMove*_lY*_r;
  }
  else{
    _pY -= _deltaMove*_lY*_r; 
  }
  
  setLookAt();
}

void Camera::calcLineSight(){
  _lX = sin(_theta)*cos(_beta);
  _lZ = sin(_theta)*sin(_beta);  
  _lY = cos(_theta);
}

void Camera::setLookAt(){
  glLoadIdentity();
  gluLookAt(_pX, _pY, _pZ,
	    _pX + _lX, _pY + _lY, _pZ + _lZ,
	    _uvX, _uvY, _uvZ);
}

void Camera::setUpVector(GLfloat x, GLfloat y, GLfloat z){
  _uvX = x, _uvY = y, _uvZ = z;
  setLookAt();
}


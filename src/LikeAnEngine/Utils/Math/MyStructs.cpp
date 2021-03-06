/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  14 - August - 2009
*/


#include "MyStructs.h"


//MyVector3d Class Methods ---------------------------------------------
//Constructors -------------------
MyVector3d::MyVector3d():_x(0.0), _y(0.0),_z(0.0){}

MyVector3d::MyVector3d(double x, double y, double z){
  _x = x;
  _y = y;
  _z = z;
}
//--------------------------------

//The getters for the points------
double MyVector3d::getX(){
  return _x;
}
double MyVector3d::getY(){
  return _y;
}
double MyVector3d::getZ(){
  return _z;
}
//--------------------------------

//This method calculate the norm(lenght) of the vector and
//return it
double MyVector3d::getNorm(){
 return sqrt(_x*_x + _y*_y + _z*_z);
}


MyVector3d MyVector3d::operator+(MyVector3d &add){
  return MyVector3d(_x+add.getX(), _y+add.getY(), _z+add.getZ());  
}


MyVector3d MyVector3d::operator-(MyVector3d &sub){
  return MyVector3d(_x-sub.getX(), _y-sub.getY(), _z-sub.getZ());
}

MyVector3d MyVector3d::operator*(double mult){
  return MyVector3d(_x*mult, _y*mult, _z*mult);
}

MyVector3d MyVector3d::operator/(double divisor){
  return MyVector3d(_x/divisor, _y/divisor, _z/divisor);
}

/*
  This method normalize this vector (it means that the normof this
  vector becomes is 1)
  To do this v (vector unitary) = u(this vector)/ |u|(norm of u)
  and |u| = sqrt(x*x + y*y + z*z)
*/
void MyVector3d::normalize(){
  double norm = getNorm();
  _x = _x/norm;
  _y = _y/norm;
  _z = _z/norm;
}


/*
  This method make the dot operation between this vector (says vector u)
  and the vector v passed as parameter = (u.v)
  The dot operation is = Xu*Xv + Yu*Yv + Zu*Zv
*/
double MyVector3d::dot(MyVector3d v){
  return (_x*v.getX() + _y*v.getY() + _z*v.getZ() );
}

/*
  This method is the implementation of the cross product
  (X), between two vectors
*/
MyVector3d MyVector3d::cross(MyVector3d v){
  double x = _y*v.getZ() - v.getY()*_z;
  double y = _x*v.getZ() - v.getX()*_z;
  double z = _x*v.getY() - v.getX()*_y;

  MyVector3d answer(x,y,z);
  return answer;
}

MyVector3d MyVector3d::cross(MyVector3d *v){
  double x = _y*v->getZ() - v->getY()*_z;
  double y = _x*v->getZ() - v->getX()*_z;
  double z = _x*v->getY() - v->getX()*_y;

  MyVector3d answer(x,y,z);
  return answer;
  }


//-------------------------------------------------------------------------






//MyPoint3d Class Methods -------------------------------------------------

//Constructors -------------------
MyPoint3d::MyPoint3d():_x(0), _y(0), _z(0){}

MyPoint3d::MyPoint3d(double x, double y, double z){
  _x = x;
  _y = y;
  _z = z;
}
//--------------------------------

//The getters for the points------
double MyPoint3d::getX(){
  return _x;
}
double MyPoint3d::getY(){
  return _y;
}
double MyPoint3d::getZ(){
  return _z;
}
//--------------------------------


MyPoint3d MyPoint3d::operator*(double mult){
  return MyPoint3d(_x*mult, _y*mult, _z*mult);
}

MyPoint3d MyPoint3d::operator+(double add){
  return MyPoint3d(_x+add, _y+add, _z+add);
}

MyPoint3d MyPoint3d::operator+(MyPoint3d p){
  return MyPoint3d(_x+p.getX(), _y+p.getY(), _z+p.getZ());
}



MyPoint3d MyPoint3d::operator-(double subs){
  return MyPoint3d(_x-subs, _y-subs, _z-subs);
}


//----------------------------------------------------------------------





//MyPoint3i Class Methods -------------------------------------------------

//Constructors -------------------
MyPoint3i::MyPoint3i(): _x(0.0), _y(0.0), _z(0.0){}

MyPoint3i::MyPoint3i(int x,int y, int z){
  _x = x;
  _y = y;
  _z = z;
}
//--------------------------------

//The getters for the points------
int MyPoint3i::getX(){
  return _x;
}
int MyPoint3i::getY(){
  return _y;
}
int MyPoint3i::getZ(){
  return _z;
}
//--------------------------------


/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  14 - August - 2009

  This file contain tree classes and its operations were defined in the MyStructs.cpp file.
  A representation of an vector <x,y,z> and a representation
  of a point (x,y,z) with x,y,z doubles, and a point
  with (x,y,z) as ints and some basics operations
*/

//This make that if so much classes uses this header, it will be compiled only once
#ifndef _MYSTRUCTS_H_
#define _MYSTRUCTS_H_


#include <cmath>
//This class manage and represents a vector <x,y,z> with x,y,z as doubles
class MyVector3d{

public:
  MyVector3d();
  MyVector3d(double x, double y, double z);
  double getX();
  double getY();
  double getZ();
  double getNorm();

  //We overload the operators
  MyVector3d operator+(MyVector3d &add);
  MyVector3d operator-(MyVector3d &sub);
  MyVector3d operator*(double mult);
  MyVector3d operator/(double divisor);
  
  void normalize();
  double dot(MyVector3d v);
  MyVector3d cross(MyVector3d v);
  MyVector3d cross(MyVector3d *v);

  // MyVector3d& operator+(const MyVector3d& v);

private:
  double _x;//Each point of the vector
  double _y;//''
  double _z;//''
};

//This class is to represent a point in 3D (x,y,z) with x,y,z as doubles
class MyPoint3d{

public:
  MyPoint3d();
  MyPoint3d(double x, double y, double z);
  double getX();
  double getY();
  double getZ();
  MyPoint3d operator*(double mult);
  MyPoint3d operator+(double add);
  MyPoint3d operator+(MyPoint3d p);
  MyPoint3d operator-(double subs);

private:
  double _x;//Each coordinate for the point
  double _y;//''
  double _z;//''
};



//This class is to represent a point in 3D (x,y,z) with x,y,z as ints
class MyPoint3i{

public:
  MyPoint3i();
  MyPoint3i(int x, int y, int z);
  int getX();
  int getY();
  int getZ();

private:
  int _x;//Each coordinate for the point
  int _y;//''
  int _z;//''
};


#endif

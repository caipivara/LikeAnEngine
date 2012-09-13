/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  21/August/2009
*/

#include "CollitionsMath.h"



bool spherePlaneCollision(Sphere *s, Plane *p){
  MyVector3d *vPoint, *vPlane, *norm;
  MyPoint3d *vert1, *vert2;
  MyPoint3d *p1, *p2, *p3, *p4;

  p1 = p->getVertex1();
  norm = p->getNormal();

  MyVector3d vPS(p1->getX() - s->getPosX(), p1->getY()- s->getNextPosY(), p1->getZ() - s->getPosZ() );
  double distance = norm->dot(vPS);

  if(distance < 0.0) distance = -distance;
  distance /= norm->getNorm();

  if (distance < s->getRadius()){//Now wee see if there are really a collision on the plane

    p2 = p->getVertex2();
    p3 = p->getVertex3();
    p4 = p->getVertex4();

    for(int i = 0; i < 4; i++){//One for each side of the plane

      if(i == 0){
	vert1 = p->getVertex1();
	vert2 = p->getVertex2();
      }
      if(i == 1){
	vert1 = p->getVertex2();
	vert2 = p->getVertex3();
      }
      if(i == 2){
	vert1 = p->getVertex3();
	vert2 = p->getVertex4();
      }
      if(i == 3){
	vert1 = p->getVertex4();
	vert2 = p->getVertex1();
      }

      vPlane = new MyVector3d(vert2->getX()- vert1->getX(), vert2->getY()- vert1->getY(), vert2->getZ() - vert1->getZ() );
      vPoint = new MyVector3d(s->getPosX() - vert1->getX(),s->getNextPosY() - vert1->getY(),s->getPosZ() - vert1->getZ());

      MyVector3d vResult = vPlane->cross(vPoint);

      //Check if the plane is the xz, if yes the cross point always will go in direction of y (in) or -y (not in the plane)
      if(p1->getY() == p2->getY() && p2->getY() == p3->getY() && p3->getY() == p4->getY()){
	if(vResult.getY() < 0){
	  delete vPlane;
	  delete vPoint;
	  //delete &vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
	  return false;//If the direction of vector result go down using the right hand tecnique
	}
      }

      //Check if the plane is the xy, if yes the cross point always will go in direction of z (in) or -z (not in the plane)
      else if(p1->getZ() == p2->getZ() && p2->getZ() == p3->getZ() && p3->getZ() == p4->getZ()){
	if(vResult.getZ() < 0){
	  delete vPlane;
	  delete vPoint;
	  //delete &vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
	  return false;//If the direction of vector result go down using the right hand tecnique
	}
      }

      //If is not the xy or the xz plane, the yz plane is the last one
      else{
	if(vResult.getX() < 0){
	  delete vPlane;
	  delete vPoint;
	  //delete &vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
	  return false;//If the direction of vector result go down using the right hand tecnique
	}
      }
      delete vPlane;
	  delete vPoint;
	  //delete vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
    }
    return true;
  }

  else {
    delete p1;
    delete norm;//Clean memory
    return false;
  }
}


/*
  Works equals like spherePlaneCollision
*/
bool cubePlaneCollision(Cube *c, Plane *p){
  MyVector3d *vPoint, *vPlane, *norm;
  MyPoint3d *vert1, *vert2;
  MyPoint3d *p1, *p2, *p3, *p4;

  norm = p->getNormal();
  p1 = p->getVertex1();

  MyVector3d vPS(p1->getX() - c->getPosX(), p1->getY()- c->getNextPosY(), p1->getZ() - c->getPosZ());

  double distance = norm->dot(vPS);

  if(distance < 0.0) distance = -distance;
  distance /= norm->getNorm();

  if (distance < c->getSide()/2){//Now wee see if there are really a collision on the plane

    p2 = p->getVertex2();
    p3 = p->getVertex3();
    p4 = p->getVertex4();

    for(int i = 0; i < 4; i++){//One for each side of the plane

      if(i == 0){
	vert1 = p->getVertex1();
	vert2 = p->getVertex2();
      }
      if(i == 1){
	vert1 = p->getVertex2();
	vert2 = p->getVertex3();
      }
      if(i == 2){
	vert1 = p->getVertex3();
	vert2 = p->getVertex4();
      }
      if(i == 3){
	vert1 = p->getVertex4();
	vert2 = p->getVertex1();
      }

      vPlane = new MyVector3d(vert2->getX()- vert1->getX(), vert2->getY()- vert1->getY(), vert2->getZ()- vert1->getZ() );
      vPoint = new MyVector3d(c->getPosX() - vert1->getX(),c->getNextPosY() - vert1->getY(),c->getPosZ() - vert1->getZ());

      MyVector3d vResult = vPlane->cross(vPoint);

      //Check if the plane is the xz, if yes the cross point always will go in direction of y (in) or -y (not in the plane)
      if(p1->getY() == p2->getY() && p2->getY() == p3->getY() && p3->getY() == p4->getY()){
	if(vResult.getY() < 0){
	  delete vPlane;
	  delete vPoint;
	  //delete vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
	  return false;//If the direction of vector result go down using the right hand tecnique
	}
      }

      //Check if the plane is the xy, if yes the cross point always will go in direction of z (in) or -z (not in the plane)
      else if(p1->getZ() == p2->getZ() && p2->getZ() == p3->getZ() && p3->getZ() == p4->getZ()){
	if(vResult.getZ() < 0){
	  delete vPlane;
	  delete vPoint;
	  //delete vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
	  return false;//If the direction of vector result go down using the right hand tecnique
	}
      }

      //If is not the xy or the xz plane, the yz plane is the last one
      else{
	if(vResult.getX() < 0){
	  delete vPlane;
	  delete vPoint;
	  //delete vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
	  return false;//If the direction of vector result go down using the right hand tecnique
	}
      }
      delete vPlane;
	  delete vPoint;
	  //delete vResult;
	  delete vert1;
	  delete vert2;
	  delete p1;
	  delete p2;
	  delete p3;
	  delete p4;
	  delete norm;//Clean memory
    }
    return true;
  }
  else {

    delete p1;
    delete norm;//Clean memory
    return false;
  }
}

int cubeSphereFacesCollision(Sphere *s, Cube *c){
  Plane *p = c->getUpFace();
  if(spherePlaneCollision(s, p)){return 0;}
  delete p;

  p = c->getDownFace();
  if(spherePlaneCollision(s, p)){return 1;}
  delete p;

  p = c->getLeftFace();
  if(spherePlaneCollision(s, p)){return 2;}
  delete p;

  p = c->getRightFace();
  if(spherePlaneCollision(s, p)){return 3;}
  delete p;

  p = c->getFrontFace();
  if(spherePlaneCollision(s, p)){return 4;}
  delete p;

  p = c->getBackFace();
  if(spherePlaneCollision(s, p)){return 5;}
  delete p;

  return -1;
}

bool cubeSphereSimpleCollision(Sphere *s, Cube *c){
  double x=s->getPosX()  , y=s->getNextPosY(), z=s->getPosZ();
  double x2=c->getPosX() , y2=c->getPosY() , z2=c->getPosZ();
  double dist = distanceBetweenPoints(x,y,z, x2, y2, z2);

  if(dist < (s->getRadius()+ c->getSide()/2)){return true;}
  else{return false;}
}

bool sphereSphereCollision(Sphere *s1, Sphere *s2){
  double x=s1->getPosX()  , y=s1->getPosY(), z=s1->getPosZ();
  double x2=s2->getPosX() , y2=s2->getNextPosY() , z2=s2->getPosZ();
  double dist = distanceBetweenPoints(x,y,z, x2, y2, z2);

  if(dist < (s1->getRadius()+ s2->getRadius())){return true;}
  else{return false;}
}

double distanceBetweenPoints(double x1, double y1, double z1, double x2, double y2, double z2 ){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2));
}

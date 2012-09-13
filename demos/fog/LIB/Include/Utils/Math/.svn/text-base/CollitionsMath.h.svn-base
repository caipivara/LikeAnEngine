/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  21/August/2009
*/

//This make that if so much classes uses this header, it will be compiled only once
#ifndef _COLLITIONSMATH_H_
#define _COLLITIONSMATH_H_


#include <cmath>
#include "../../Objects/Sphere.h"
#include "../../Objects/Plane.h"
#include "../../Objects/Cube.h"


/*
  D = |vPQ.n|/||n|| -> . is dot operation
  if D == radius of the sphere, pan, the distance is iquals
  to "have the sphere on the plane or over" but how do we know if 
  the sphere is really on the plane and not in the air??

  Now
  Using the rule of the right hand,
  we form a vector from each vertex(i) of the plane to the other vertex(i+1)
  and a vector from the vertex(i) to the pos of the sphere, if the cross product of this vectors and using
  the rule of the right hand the result is negative (going down) the sphere is in the air and really not on the plane
  
  but if we do all cross product (apply the right hand rule) and it always is positive (going up)

  Now, there are 3 cases of the position of a plane, xy, xz and the others (any diferent to this we
  project it over the yz plane) and ask for the direction of the cross product as I say before. For each
  case the cross product apply the right hand go directly to diferents direcctions

  for xy it goes to z, for xz it goes to y, and for others it goes to x
*/
bool spherePlaneCollision(Sphere *s, Plane *p);

//Works equals like spherePlaneCollision
bool cubePlaneCollision(Cube *c, Plane *p);

/*
  returns 0 if collide with upFace of the cube
  returns 1 if collide with downFace of the cube
  returns 2 if collide with leftFace of the cube
  returns 3 if collide with rightFace of the cube
  returns 4 if collide with frontFace of the cube
  returns 5 if collide with backFace of the cube
  returns -1 if not collide with cube
*/
int cubeSphereFacesCollision(Sphere *s, Cube *c);

//Check if sphere collide with the cube, if yes return true, if not return false
bool cubeSphereSimpleCollision(Sphere *s, Cube *c);

bool sphereSphereCollision(Sphere *s1, Sphere *s2);

double distanceBetweenPoints(double x1, double y1, double z1, double x2, double y2, double z2 );

#endif

//Thanks to http://www.lighthouse3d.com/opengl/glut/index.php?
/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  15 - August - 2009
*/
#include "Cube.h"


//=============================Constructors=====================
Cube::Cube(){
  initValues();
  initArrays();
  setColor(0.4, 0.7, 0.1, 1.0);
}

Cube::Cube(GLdouble x, GLdouble y, GLdouble z, GLfloat side){
  initValues();//Init predef values
  //We Give the new values
  _posX = x, _posZ = z, _deltaPosX = 1.0, _deltaPosY = 1.0, _deltaPosZ = 1.0;
  setPosY(y);
  _side = side;
  initArrays();
  setColor(1.0, 1.0, 1.0, 1.0);
}

Cube::Cube(GLdouble x, GLdouble y, GLdouble z, GLfloat side, GLdouble r, GLdouble g, GLdouble b, GLdouble alpha){
  initValues();//Init predef values
  //We Give the new values
  _posX = x, _posZ = z, _deltaPosX = 1.0, _deltaPosY = 1.0, _deltaPosZ = 1.0;
  setPosY(y);
  _side = side;

  initArrays();
  setColor(r,g,b,alpha);
}

Cube::Cube(GLdouble x, GLdouble y, GLdouble z, GLfloat side, GLdouble r, GLdouble g, GLdouble b, GLdouble alpha ,GLdouble ambiental[4], GLdouble diffuse[4], GLdouble specular[4]){
  initValues();//Init predef values
  //We Give the new values
  _posX = x ,_posZ = z, _deltaPosX = 1.0, _deltaPosY = 1.0, _deltaPosZ = 1.0;
  setPosY(y);
  _side = side;

  _matAmbient[0] = ambiental[0] ,_matAmbient[1] = ambiental[1],_matAmbient[2] = ambiental[2], _matAmbient[3] = ambiental[3];
  _matDiffuse[0] = diffuse[0] ,_matDiffuse[1] = diffuse[1],_matDiffuse[2] = diffuse[2], _matDiffuse[3] = diffuse[3];
  _matSpecular[0] = specular[0] ,_matSpecular[1] = specular[1] ,_matSpecular[2] = specular[2] , _matSpecular[3] = specular[3];

  initArrays();
  setColor(r,g,b,alpha);
}

void Cube::initValues(){
  _posX = 0.0,_posZ = 0.0, _deltaPosX = 1.0, _deltaPosY = 1.0, _deltaPosZ = 1.0;
  setPosY(0.0);
  _side = 10.0;

  _matAmbient[0] = 0.5 ,_matAmbient[1] = 0.0,_matAmbient[2] = 0.5, _matAmbient[3] = 1.0;
  _matDiffuse[0] = 0.0 ,_matDiffuse[1] = 0.3,_matDiffuse[2] = 0.1, _matDiffuse[3] = 1.0;
  _matSpecular[0] = 1.0 ,_matSpecular[1] = 0.8,_matSpecular[2] = 0.3, _matSpecular[3] = 1.0;

  _velocity = -2.0;
  _timeJump = 0.0;
  _angleParabolicMove = 30.0;
  _state = ' ';
}

// cube ///////////////////////////////////////////////////////////////////////
//    v5----- v6
//   /|      /|
//  v1------v2|
//  | |     | |
//  | |v4---|-|v7
//  |/      |/
//  v0------v3             -> for the vertex array

void Cube::initArrays(){
  //Fill the vertex arrays
  _arrayV[0] = -_side/2; _arrayV[1] = _side/2; _arrayV[2] =  _side/2;//Up vertexs
  _arrayV[3] = -_side/2; _arrayV[4] = _side/2; _arrayV[5] =  -_side/2;
  _arrayV[6] = _side/2; _arrayV[7] = _side/2; _arrayV[8] = -_side/2;
  _arrayV[9] = _side/2; _arrayV[10] = _side/2; _arrayV[11] = _side/2;

  _arrayV[12] = -_side/2; _arrayV[13] = -_side/2; _arrayV[14] = _side/2;//Down vertexs
  _arrayV[15] = -_side/2; _arrayV[16] = -_side/2; _arrayV[17] = -_side/2;
  _arrayV[18] = _side/2; _arrayV[19] = -_side/2; _arrayV[20] = -_side/2;
  _arrayV[21] = _side/2; _arrayV[22] = -_side/2; _arrayV[23] = _side/2;

  _arrayV[24] = -_side/2; _arrayV[25] = -_side/2; _arrayV[26] = -_side/2;//Left vertexs
  _arrayV[27] = -_side/2; _arrayV[28] = _side/2; _arrayV[29] = -_side/2;
  _arrayV[30] = -_side/2; _arrayV[31] = _side/2; _arrayV[32] = _side/2;
  _arrayV[33] = -_side/2; _arrayV[34] = -_side/2; _arrayV[35] = _side/2;

  _arrayV[36] = _side/2; _arrayV[37] = -_side/2; _arrayV[38] = -_side/2;//Right vertexs
  _arrayV[39] = _side/2; _arrayV[40] = _side/2; _arrayV[41] = -_side/2;
  _arrayV[42] = _side/2; _arrayV[43] = _side/2; _arrayV[44] = _side/2;
  _arrayV[45] = _side/2; _arrayV[46] = -_side/2; _arrayV[47] = _side/2;

  _arrayV[48] = _side/2; _arrayV[49] = -_side/2; _arrayV[50] = _side/2;// Front vertex
  _arrayV[51] = _side/2; _arrayV[52] = _side/2; _arrayV[53] = _side/2;
  _arrayV[54] = -_side/2; _arrayV[55] = _side/2; _arrayV[56] = _side/2;
  _arrayV[57] = -_side/2; _arrayV[58] = -_side/2; _arrayV[59] = _side/2;

  _arrayV[60] = _side/2; _arrayV[61] = -_side/2; _arrayV[62] = -_side/2;//Back vertexs
  _arrayV[63] = _side/2; _arrayV[64] = _side/2; _arrayV[65] = -_side/2;
  _arrayV[66] = -_side/2; _arrayV[67] = _side/2; _arrayV[68] = -_side/2;
  _arrayV[69] = -_side/2; _arrayV[70] = -_side/2; _arrayV[71] = -_side/2;


  for(int i = 0; i + 2 < 72; i+= 3){
    _arrayN[i] = 0.0; _arrayN[i+1] = 1.0; _arrayN[i+2] = 0.0;
  }

  _arrayT[0] = 1.0;  _arrayT[1] = 0.0;   _arrayT[2] = 1.0;  _arrayT[3] = 1.0;//front
  _arrayT[4] = 0.0;  _arrayT[5] = 1.0;   _arrayT[6] = 0.0;  _arrayT[7] = 0.0;

  _arrayT[8] = 1.0;  _arrayT[9] = 0.0;   _arrayT[10]= 1.0;  _arrayT[11]= 1.0;//Back
  _arrayT[12]= 0.0;  _arrayT[13]= 1.0;   _arrayT[14]= 0.0;  _arrayT[15]= 0.0;

  _arrayT[16]= 1.0;  _arrayT[17]= 0.0;   _arrayT[18]= 1.0;  _arrayT[19]= 1.0;//Down
  _arrayT[20]= 0.0;  _arrayT[21]= 1.0;   _arrayT[22]= 0.0;  _arrayT[23]= 0.0;

  _arrayT[24]= 1.0;  _arrayT[25]= 0.0;   _arrayT[26]= 1.0;  _arrayT[27]= 1.0;//Up
  _arrayT[28]= 0.0;  _arrayT[29]= 1.0;   _arrayT[30]= 0.0;  _arrayT[31]= 0.0;

  _arrayT[32]= 1.0;  _arrayT[33]= 0.0;   _arrayT[34]= 1.0;  _arrayT[35]= 1.0;//Right
  _arrayT[36]= 0.0;  _arrayT[37]= 1.0;   _arrayT[38]= 0.0;  _arrayT[39]= 0.0;

  _arrayT[40]= 1.0;  _arrayT[41]= 0.0;   _arrayT[42]= 1.0;  _arrayT[43]= 1.0;//Left
  _arrayT[44]= 0.0;  _arrayT[45]= 1.0;   _arrayT[46]= 0.0;  _arrayT[47]= 0.0;
}
//============================================================

void Cube::jump(){
  GLdouble time = clock();

  _nextPosY = _velocity*(sin(_angleParabolicMove))*_timeJump - (GRAVITY*_timeJump*_timeJump)/2 +_initPosY;
  _timeJump += DELTA_FALL_TIME;

  //----------------"delay" manual----------------------
  while ((clock() - time) < 0.01*CLOCKS_PER_SEC){}
  //----------------------------------------------------
}


void Cube::draw(){
  glPushMatrix();

     glEnableClientState(GL_VERTEX_ARRAY);
     glEnableClientState(GL_COLOR_ARRAY);
     glEnableClientState(GL_NORMAL_ARRAY);
     glEnableClientState(GL_TEXTURE_COORD_ARRAY);

     glVertexPointer(3, GL_DOUBLE, 0, _arrayV);
     glColorPointer(4, GL_FLOAT, 0, _arrayC);
     glNormalPointer(GL_FLOAT, 0, _arrayN);
     glTexCoordPointer(2, GL_FLOAT, 0, _arrayT);

     glEnable(GL_BLEND);
     glEnable(GL_TEXTURE_2D);

	glMaterialfv (GL_FRONT, GL_AMBIENT, _matAmbient);
	glMaterialfv (GL_FRONT, GL_DIFFUSE, _matDiffuse);
	glMaterialfv (GL_FRONT, GL_SPECULAR, _matSpecular);
	glMaterialf (GL_FRONT, GL_SHININESS, HIGH_SHININESS);

	glTranslatef(_posX, _posY, _posZ);

	//glPolygonMode(GL_FRONT, GL_FILL);
  	//glPolygonMode(GL_BACK, GL_FILL);

	glBindTexture(GL_TEXTURE_2D, _tex[0]);
	glDrawArrays( GL_QUADS, 0, 24 );

     glDisable( GL_TEXTURE_2D );
     glDisable(GL_BLEND);
     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
     glDisableClientState(GL_NORMAL_ARRAY);
     glDisableClientState(GL_VERTEX_ARRAY);
     glDisableClientState(GL_COLOR_ARRAY);

  glPopMatrix();
}

void Cube::moveInX(bool positive){
  if(positive)_posX += _deltaPosX;
  else _posX -= _deltaPosX;
}

void Cube::moveInY(bool positive){
  if(positive)_posY += _deltaPosY;
  else _posY -= _deltaPosY;
  setPosY(_posY);
}

void Cube::moveInZ(bool positive){
  if(positive)_posZ += _deltaPosZ;
  else _posZ -= _deltaPosZ;
}

void Cube::actualizePos(){
  _posY = _nextPosY;
}



//============= GETTERS-SETTERS ===========================


void Cube::setTextures(GLuint texGen){
  for(int i = 0; i < 6; i++){
    _tex[i] = texGen;
  }
}

void Cube::setTextureUp(GLuint tex){_tex[0] = tex;}
void Cube::setTextureDown(GLuint tex){_tex[1] = tex;}
void Cube::setTextureLeft(GLuint tex){_tex[2] = tex;}
void Cube::setTextureRight(GLuint tex){_tex[3] = tex;}
void Cube::setTextureFront(GLuint tex){_tex[4] = tex;}
void Cube::setTextureBack(GLuint tex){_tex[5] = tex;}


void Cube::setColor(GLdouble r, GLdouble g, GLdouble b, GLdouble alpha){
  for(int i = 0; i+3 < 96; i+=4){
    _arrayC[i] = r; _arrayC[i+1] = g; _arrayC[i+2] = b; _arrayC[i+3] = alpha;
  }
}


void Cube::setPosY(GLdouble pos){
  _posY = pos;
  _nextPosY = pos;
  _initPosY = pos;
}

void Cube::setState(char state){
  _state = state;
  if(_state == ' '){
    _timeJump = 0.0;
  }
  if(_state == 'c'){
    _timeJump = 0.0;
     _state = ' ';
  }
}

Plane* Cube::getRealUpFace(){
  GLdouble vert[12] = {_arrayV[0],_arrayV[1],_arrayV[2], _arrayV[3],_arrayV[4],_arrayV[5],
		       _arrayV[6],_arrayV[7],_arrayV[8], _arrayV[9],_arrayV[10],_arrayV[11] };
  return new Plane(vert);
}

Plane* Cube::getRealDownFace(){
  GLdouble vert[12] = {_arrayV[12],_arrayV[13],_arrayV[14], _arrayV[15],_arrayV[16],_arrayV[17],
		       _arrayV[18],_arrayV[19],_arrayV[20], _arrayV[21],_arrayV[22],_arrayV[23] };
  return new Plane(vert);
}

Plane* Cube::getRealLeftFace(){
  GLdouble vert[12] = {_arrayV[24],_arrayV[25],_arrayV[26], _arrayV[27],_arrayV[28],_arrayV[29],
		       _arrayV[30],_arrayV[31],_arrayV[32], _arrayV[33],_arrayV[34],_arrayV[35]};
  return new Plane(vert);
}

Plane* Cube::getRealRightFace(){
  GLdouble vert[12] = {_arrayV[36],_arrayV[37],_arrayV[38], _arrayV[39],_arrayV[40],_arrayV[41],
		       _arrayV[42],_arrayV[43],_arrayV[44], _arrayV[45],_arrayV[46],_arrayV[47] };
  return new Plane(vert);
}

Plane* Cube::getRealFrontFace(){
  GLdouble vert[12] = {_arrayV[48],_arrayV[49],_arrayV[50], _arrayV[51],_arrayV[52],_arrayV[53],
		       _arrayV[54],_arrayV[55],_arrayV[56], _arrayV[57],_arrayV[58],_arrayV[59] };
  return new Plane(vert);
}

Plane* Cube::getRealBackFace(){
  GLdouble vert[12] = {_arrayV[60],_arrayV[61],_arrayV[62], _arrayV[63],_arrayV[64],_arrayV[65],
		       _arrayV[66],_arrayV[67],_arrayV[68], _arrayV[69],_arrayV[70],_arrayV[71] };
  return new Plane(vert);
}



Plane* Cube::getUpFace(){
  GLdouble vert[12] = {_arrayV[0]+_posX,_arrayV[1]+_posY,_arrayV[2]+_posZ, _arrayV[3]+_posX,_arrayV[4]+_posY,_arrayV[5]+_posZ,
		       _arrayV[6]+_posX,_arrayV[7]+_posY,_arrayV[8]+_posZ, _arrayV[9]+_posX,_arrayV[10]+_posY,_arrayV[11]+_posZ };
  return new Plane(vert);
}

Plane* Cube::getDownFace(){
  GLdouble vert[12] = {_arrayV[12]+_posX,_arrayV[13]+_posY,_arrayV[14]+_posZ, _arrayV[15]+_posX,_arrayV[16]+_posY,_arrayV[17]+_posZ,
		       _arrayV[18]+_posX,_arrayV[19]+_posY,_arrayV[20]+_posZ, _arrayV[21]+_posX,_arrayV[22]+_posY,_arrayV[23]+_posZ };
return new Plane(vert);
}

Plane* Cube::getLeftFace(){
  GLdouble vert[12] = {_arrayV[24]+_posX,_arrayV[25]+_posY,_arrayV[26]+_posZ, _arrayV[27]+_posX,_arrayV[28]+_posY,_arrayV[29]+_posZ,
		       _arrayV[30]+_posX,_arrayV[31]+_posY,_arrayV[32]+_posZ, _arrayV[33]+_posX,_arrayV[34]+_posY,_arrayV[35]+_posZ };
  return new Plane(vert);
}

Plane* Cube::getRightFace(){
  GLdouble vert[12] = {_arrayV[36]+_posX,_arrayV[37]+_posY,_arrayV[38]+_posZ, _arrayV[39]+_posX,_arrayV[40]+_posY,_arrayV[41]+_posZ,
		       _arrayV[42]+_posX,_arrayV[43]+_posY,_arrayV[44]+_posZ, _arrayV[45]+_posX,_arrayV[46]+_posY,_arrayV[47]+_posZ };
  return new Plane(vert);
}

Plane* Cube::getFrontFace(){
  GLdouble vert[12] = {_arrayV[48]+_posX,_arrayV[49]+_posY,_arrayV[50]+_posZ, _arrayV[51]+_posX,_arrayV[52]+_posY,_arrayV[53]+_posZ,
		       _arrayV[54]+_posX,_arrayV[55]+_posY,_arrayV[56]+_posZ, _arrayV[57]+_posX,_arrayV[58]+_posY,_arrayV[59]+_posZ };
  return new Plane(vert);
}

Plane* Cube::getBackFace(){
  GLdouble vert[12] = {_arrayV[60]+_posX,_arrayV[61]+_posY,_arrayV[62]+_posZ, _arrayV[63]+_posX,_arrayV[64]+_posY,_arrayV[65]+_posZ,
		       _arrayV[66]+_posX,_arrayV[67]+_posY,_arrayV[68]+_posZ, _arrayV[69]+_posX,_arrayV[70]+_posY,_arrayV[71]+_posZ };
  return new Plane(vert);
}

GLdouble Cube::getState(){return _state;}
GLdouble Cube::getSide(){return _side;}
GLdouble Cube::getPosX(){return _posX;}
GLdouble Cube::getPosY(){return _posY;}
GLdouble Cube::getNextPosY(){return _nextPosY;}
GLdouble Cube::getPosZ(){return _posZ;}


//==========================================================

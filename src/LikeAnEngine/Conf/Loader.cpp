/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  27 - September - 2009
*/

#include "Loader.h"


//Constructors ----------------------------------------------------------
Loader::Loader(){
  load();
}
//--------------------------------------------------------------------------

void Loader::load(){
  string type = "";
  uint aM = 0;//number of the actual model reading
    
  printf("\n========= Start Reading World Configuration ======\n");
  freopen( PATH_FILE.c_str(), "r",stdin);
   
  while(cin >>type){
	
    if(type[0] != '#'){
      if(type == "-limits"){
	cin >> ns;
	_arraySpheres = new Sphere[ns];
	    
	cin >> np;
	_arrayPlanes = new Plane[np];
	    
	cin >> nc;
	_arrayCubes = new Cube[nc];
	    
	cin >> nl;
	_arrayLights = new Light[nl];
	    
	cin >> nt;
	_arrayTexturesId = new GLuint[nt];
	_arrayNameTextures = new string[nt];
	_arrayImages = new Image[nt];
	    

	cin >> nm;
	_arrayTempModels = new Model[nm];
	_arrayModels = new Model3DS[nm];

      }
      else if(type == "-textures"){
	string tex;
	for(int i = 0; i < nt; i++){
	  cin >> tex;
	  _arrayNameTextures[i] += CARPET_FILES + CARPET_TEXTURES+ tex;
	}
	initTextures();
      }
	  
      else if(type == "-cam"){
	GLdouble x,y,z,deltaM, upX, upY, upZ;
	GLfloat theta,beta, deltaT, deltaB;
	    
	cin >> x >> y >> z >> deltaM >> upX >> upY >> upZ;
	cin >> theta >> beta >> deltaT >> deltaB;
	    
	printf("              - Camera Readed\n");
	_camera = new Camera(x,y,z,deltaT,deltaB,deltaM,theta,beta);
      }
      else if(type == "-sphere"){
	GLdouble x,y,z;
	GLfloat rad, r,g,b,alpha,amb[4], dif[4], spec[4];
	GLuint tex;
	    
	    
	cin >> x >> y >> z >> rad;
	cin >> r >> g >> b >> alpha;
	cin >> amb[0] >> amb[1] >> amb[2] >> amb[3];
	cin >> dif[0] >> dif[1] >> dif[2] >> dif[3];
	cin >> spec[0] >> spec[1] >> spec[2] >> spec[3];
	    
	cin >> tex;
	    
	tex--;
	addSphere(new Sphere(x,y,z,rad,r,g,b,alpha ,amb, dif, spec), tex);
      }
      else if(type == "-cube"){
	GLdouble x,y,z,amb[4], dif[4], spec[4];
	GLfloat side, r,g,b,alpha;
	GLuint tex;
	    
	cin >> x >> y >> z >> side;
	cin >> r >> g >> b >> alpha;
	cin >> amb[0] >> amb[1] >> amb[2] >> amb[3];
	cin >> dif[0] >> dif[1] >> dif[2] >> dif[3];
	cin >> spec[0] >> spec[1] >> spec[2] >> spec[3];
	cin >> tex;
	    
	tex--;
	addCube(new Cube(x,y,z,side,r,g,b,alpha ,amb, dif, spec), tex);
      }
      else if(type == "-plane"){
	GLdouble vectors[12],amb[4], dif[4], spec[4], x,y,z;
	GLfloat r,g,b,alpha, coord[8];
	GLuint tex;
	    
	cin >> vectors[0]>>vectors[1]>>vectors[2];
	cin >> vectors[3]>>vectors[4]>>vectors[5];
	cin >> vectors[6]>>vectors[7]>>vectors[8];
	cin >> vectors[9]>>vectors[10]>>vectors[11];
	    
	cin >> x >> y >> z;
	cin >> r >> g >> b>>alpha;
	    
	cin >> amb[0] >> amb[1] >> amb[2] >> amb[3];
	cin >> dif[0] >> dif[1] >> dif[2] >> dif[3];
	cin >> spec[0] >> spec[1] >> spec[2] >> spec[3];
	    
	cin >> tex;
	cin >> coord[0] >>coord[1] >>coord[2] >>coord[3] >>coord[4];
	cin >> coord[5] >>coord[6] >>coord[7];
	    
	tex--;
	    
	addPlane(new Plane(vectors, r,g,b,alpha,amb,dif,spec), tex,x,y,z, coord);
      }
      else if(type=="-light"){
	GLfloat attC,attL,attQ, ambiental[4], diffuse[4], specular[4] , p[4]; 
	p[3] = 1.0;
	    
	cin >> p[0] >> p[1] >> p[2];
	cin >> ambiental[0]>> ambiental[1]>> ambiental[2]>>ambiental[3];
	cin >> diffuse[0]>> diffuse[1]>> diffuse[2]>>diffuse[3];
	cin >> specular[0]>> specular[1]>> specular[2]>> specular[3];
	cin >> attC >> attL >> attQ;
	addLight(new Light(ambiental, diffuse, specular,p),attC,attL,attQ);
      }
      else if(type=="-model"){
	  cin >> _arrayTempModels[aM].name;

	  cin >> _arrayTempModels[aM].p[0]>> _arrayTempModels[aM].p[1]>> _arrayTempModels[aM].p[2];
	  cin >> _arrayTempModels[aM].deltaP[0]>> _arrayTempModels[aM].deltaP[1]>> _arrayTempModels[aM].deltaP[2];
	  

	  cin >> _arrayTempModels[aM].ma[0]>> _arrayTempModels[aM].ma[1]>> _arrayTempModels[aM].ma[2]>> _arrayTempModels[aM].ma[3];
	  cin >> _arrayTempModels[aM].md[0]>> _arrayTempModels[aM].md[1]>> _arrayTempModels[aM].md[2]>> _arrayTempModels[aM].md[3];
	  cin >> _arrayTempModels[aM].ms[0]>> _arrayTempModels[aM].ms[1]>> _arrayTempModels[aM].ms[2]>> _arrayTempModels[aM].ms[3];

	 aM++;
      }
	    
    
    }
  }
  fclose(stdin); 
  
  loadModels();
  
  printf("========= End Reading World Configuration ======\n\n");
}

void Loader::loadModels(){
  for(int i = 0; i < nm; i++){
    Model3DS model((PATH_MODELS+ _arrayTempModels[i].name).c_str(),_arrayTempModels[i].ma,_arrayTempModels[i].md,_arrayTempModels[i].ms,_arrayTempModels[i].p,_arrayTempModels[i].deltaP );
    _arrayModels[i] = model;
    printf("              - Model %s Readed \n", _arrayTempModels[i].name.c_str());
  }

}








void Loader::initTextures(){
  GLuint *arrayEnvMode = getGLTextureEnvMode(nt);
  //arrayEnvMode[0] = GL_DECAL;//Sky is decal mode, no default mode

  for(int i = 0; i < nt; i++){
    Image *imageTemp = loadBMP(_arrayNameTextures[i].c_str()); 
    _arrayImages[i] = imageTemp;
  }
  
  loadTextures(_arrayImages, (GLuint*)_arrayTexturesId,arrayEnvMode , nt);
}


void Loader::addSphere(Sphere* s, GLuint tex){
  static int cont = 0;
  printf("              - Sphere %d Readed \n", cont+1);
  _arraySpheres[cont] = *s;
  _arraySpheres[cont].setTexture(_arrayTexturesId[tex]);
  cont++;
}

void Loader::addPlane(Plane *p, GLuint tex, GLdouble x, GLdouble y, GLdouble z, GLfloat arrayC[8]){
  static int cont = 0;
  printf("              - Plane %d Readed \n", cont+1);
  _arrayPlanes[cont] = *p;
  _arrayPlanes[cont].setTexture(_arrayTexturesId[tex]);
  _arrayPlanes[cont].setPos(x,y,z);
  _arrayPlanes[cont].setTextureCoord(arrayC);
  cont++;
}

void Loader::addCube(Cube* c, GLuint tex){
  static int cont = 0;
  printf("              - Cube %d Readed \n", cont+1);
  _arrayCubes[cont] = *c;
  _arrayCubes[cont].setTextures(_arrayTexturesId[tex]);
  cont++;
}

void Loader::addLight(Light* l, GLfloat attC, GLfloat attL, GLfloat attQ){
  static int cont = 0;
  printf("              - Light %d Readed \n", cont+1);
  _arrayLights[cont] = *l;
  _arrayLights[cont].setAttenuationFacts(attC,attL,attQ);
  cont++;
}



Camera* Loader::getCamera(){return _camera;}
Sphere* Loader::getSpheres(){return _arraySpheres;}
Plane* Loader::getPlanes(){return _arrayPlanes;}
Cube* Loader::getCubes(){return _arrayCubes;}
Light* Loader::getLights(){return _arrayLights;}
GLuint* Loader::getTextures(){return _arrayTexturesId;}
Model3DS* Loader::getModels(){return _arrayModels;}

GLint Loader::getNumberS(){return ns;}
GLint Loader::getNumberP(){return np;}
GLint Loader::getNumberC(){return nc;}
GLint Loader::getNumberL(){return nl;}
GLint Loader::getNumberM(){return nm;}

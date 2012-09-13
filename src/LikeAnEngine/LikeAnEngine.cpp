/*
  Written by:
  Daniel Gomez Rico
  danielgomezrico@gmail.com
  Student of system engineering, 7 semester
  at the EAFIT university from Colombia
  7 - Jan - 2010
*/

#include "LikeAnEngine.h"

//Engine Objects
Loader *loader;
Camera *camera;
Sphere *sky;
Sphere *arraySpheres;
Plane *arrayPlanes;
Light *arrayLights;
Cube *arrayCubes;
Model3DS* arrayModels;
KeyboardManager *keyboardManager;

//Number of Enine Objects
GLfloat perspectiveAngle, fAspect;
int numSpheres;//lenght of the arrayBalls
int numPlanes;//Lenght of the arrayPlanes
int numLights;//Lenght of the arrayLights
int numCubes;//Lenght of the arrayCubes
int numModels;

//Array to manage the textures
GLuint *arrayTexturesId;

float arrayBackgroundColor[4] = {0.0, 0.0, 0.0, 1.0};

//DisplayList of the wold
//GLint worldDL;

//=== ATT TO CALCULATE FPS ==========
//GLint currTime;//the current number of miliseconds
//GLint pastTime;//The number of miliseconds since we last computed the frame rate
//GLint fps;//The number of frames since we last computed the frame rate and Frames Per Second
//=============================

const char* wName;

//Func Pointers
void (*keyboardFunc)() = NULL;
void (*displayFunc)() = NULL;



//FUNCTIONS
void init (void);
void initRendering(void);
void manageKeyboard(int x);

//void calculateFPS(int x);

//GLuint getWorldDL();

void visualizationParams(void);
void display(void);
void displayWithAditional(void);
void reshape(GLsizei w, GLsizei h);
void idle(void);

//============================= Keyboard managment ==================================
void keyboard(unsigned char key, int x, int y);
void keyboardUp(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void specialKeyUp(int key, int x, int y);
//============================= /Keyboard managment ==================================





void initEngine(int argc, char **argv, const char* windowName){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(700,700);

  wName = windowName;
  glutCreateWindow(windowName);

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);

  initRendering();
  init();
  visualizationParams();
}

void startEngineLoop(){
  glutMainLoop();
}

void  init (void)
{
  glClearColor(arrayBackgroundColor[0], arrayBackgroundColor[1], arrayBackgroundColor[2], arrayBackgroundColor[3]);

  perspectiveAngle=45;
  //currTime = 0;//the current number of miliseconds
  //pastTime = 0;//The number of miliseconds since we last computed the frame rate
  //fps = 0.0;//The number of frames since we last computed the frame rate and Frames Per Second

  keyboardManager = new KeyboardManager();
  loader = new Loader();

  numSpheres = loader->getNumberS();
  numLights = loader->getNumberL();
  numPlanes = loader->getNumberP();
  numCubes = loader->getNumberC();
  numModels = loader->getNumberM();

  camera = loader->getCamera();
  arrayTexturesId = loader->getTextures();
  arrayCubes = loader->getCubes();
  arrayPlanes = loader->getPlanes();
  arrayLights = loader->getLights();
  arraySpheres = loader->getSpheres();
  arrayModels = loader->getModels();

  for(int i = 0; i < numLights; i++){
    arrayLights[i].enableGLLight(i);
  }

  sky = new Sphere(arrayPlanes[0].getPosX(), arrayPlanes[0].getPosY(), arrayPlanes[0].getPosZ(), 999.0);//Centred

  sky->setTexture(arrayTexturesId[2]);
  sky->setColor(1.0, 1.0, 1.0, 1.0);

  //worldDL = getWorldDL();

  //glutTimerFunc(500, calculateFPS, 1);
}

void  initRendering(void){
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  //glEnable(GL_RESCALE_NORMAL);//Assumes that normals will be normalized
  glEnable(GL_COLOR_MATERIAL);
  //glEnable(GL_CULL_FACE);
  glShadeModel(GL_SMOOTH);

  glLightModelf (GL_LIGHT_MODEL_LOCAL_VIEWER, 1.0);
  //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
  //glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
  //glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
  //glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SINGLE_COLOR);
}

//Init the world display list and return it
/*GLuint  getWorldDL() {
  glPushMatrix();
  GLuint DLid;
  DLid = glGenLists(1);
  glNewList(DLid,GL_COMPILE);

  for(int i = 0; i < numPlanes; i++){ arrayPlanes[i].draw();}
  for(int i = 0; i < numCubes; i++){ arrayCubes[i].draw();}


  glEndList();
  glPopMatrix();
  return DLid;
}*/


/*void  idle(void){
  //MANAGE THE COLLISION CHECK

  for(int j = 0; j < numPlanes; j++){//Check planes
    if(spherePlaneCollision(&arraySpheres[0], &arrayPlanes[j])) {
      // printf("C %d ",j);
      arraySpheres[0].setState('c');//The ball is in the floor
      break;
    }
    else {
      // printf("N %d ", j);
      arraySpheres[0].actualizePos();
    }
    }
}*/
  //printf("\n");


  /*for(int j = 1; j < numSpheres; j++){//Check Spheres
    if(sphereSphereCollision(&arraySpheres[0], &arraySpheres[j] )){
      GLfloat s[3] = {0.0, 0.0, 0.0};
      arraySpheres[j].setScale(s);
       }
  }



  //glutPostRedisplay();

}*/

/* In Devel
void  calculateFPS(int x){
  currTime = glutGet(GLUT_ELAPSED_TIME);

  if (currTime - pastTime > 1000) {
    //fps = (GLfloat)(fps*1000)/(currTime-pastTime);
    pastTime = currTime;

    std::stringstream ss;
    ss << wName<< " FPS: " << fps;
    glutSetWindowTitle(ss.str().c_str());

    fps = 0;
  }

  //fps++;

  //Each 10 msec see the state of the keys pressed
  //glutTimerFunc(500, calculateFPS, 1);
}
*/

// Draw the escene
void  display(void)
{
  //fps++;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glClearColor(0.0f,0.0f,0.0f,1.0f);

  glPushMatrix();

  //glCallList(worldDL);

  for(int i = 0; i < numLights; i++){ arrayLights[i].draw();}
  for(int i = 0; i < numSpheres; i++){ arraySpheres[i].draw();}
  for(int i = 0; i < numModels; i++){ arrayModels[i].draw();}
  for(int i = 0; i < numPlanes; i++){ arrayPlanes[i].draw();}
  for(int i = 0; i < numCubes; i++){ arrayCubes[i].draw();}

  glPopMatrix();

  glFlush ();
  glutSwapBuffers();
}

// Draw the same that draw display function but calls the displayFunc after all
void  displayWithAditional(void)
{
  //fps++;
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //glClearColor(0.0f,0.0f,0.0f,1.0f);

  glPushMatrix();

  //glCallList(worldDL);

  for(int i = 0; i < numLights; i++){ arrayLights[i].draw();}
  for(int i = 0; i < numSpheres; i++){ arraySpheres[i].draw();}
  for(int i = 0; i < numModels; i++){ arrayModels[i].draw();}
  for(int i = 0; i < numPlanes; i++){ arrayPlanes[i].draw();}
  for(int i = 0; i < numCubes; i++){ arrayCubes[i].draw();}

  glPopMatrix();

  if(displayFunc != NULL)
    displayFunc();

  glFlush ();
  glutSwapBuffers();
}











//Especify the visualitation params
void  visualizationParams(void)
{
  glMatrixMode(GL_PROJECTION);  // Sistem of coordenates of projection
  glLoadIdentity();  // Load the identity matrix
  gluPerspective(perspectiveAngle,fAspect,0.1,10000); // Especify the perspective projection
  glMatrixMode(GL_MODELVIEW);  // Especify the sistem of coordenates of the model
  glLoadIdentity();  // Load the identity matrix
  camera->orientAngleCam(false, false, false, false);  //Orient the camera
}

void  reshape(GLsizei w, GLsizei h)
{

  if ( h == 0 ) h = 1;// Prebent division by 0
  glViewport(0, 0, w, h);// Size of the viewport
  fAspect = (GLfloat)w/(GLfloat)h;  // Aspect Ration
  visualizationParams();
}


//========================== KEYBOARD ==========================================
void  keyboard(unsigned char key, int x, int y){
  keyboardManager->setPress(key, true);
}

void  keyboardUp(unsigned char key, int x, int y){
  keyboardManager->setPress(key, false);
}

void  specialKey(int key, int x, int y) {
  keyboardManager->setPress(key, true);
}

void  specialKeyUp(int key, int x, int y) {
  keyboardManager->setPress(key, false);
}


void manageKeyboard(int x){
  keyboardFunc();
  glutTimerFunc(10, manageKeyboard, 1);
}
//========================== /KEYBOARD ==========================================

//============================ SETTERS =====================
void setKeyboardFunc(void(*func)()){
  keyboardFunc = func;

  glutKeyboardFunc(keyboard);
  glutKeyboardUpFunc(keyboardUp);
  glutSpecialFunc(specialKey);
  glutSpecialUpFunc(specialKeyUp);

  glutTimerFunc(10, manageKeyboard, 1); //Each 10 msec see the state of the keys pressed
}

void setIdleFunc(void(*func)(void)){
  glutIdleFunc(func);
}


void setAditionalDisplayFunc(void(*func)(void)){
  displayFunc = func;
  glutDisplayFunc(displayWithAditional);//Now the display func will be this
}


void setBackgroundColor(float color[4]){
  arrayBackgroundColor[0] = color[0];
  arrayBackgroundColor[1] = color[1];
  arrayBackgroundColor[2] = color[2];
  arrayBackgroundColor[3] = color[3];
  glClearColor(arrayBackgroundColor[0], arrayBackgroundColor[1], arrayBackgroundColor[2], arrayBackgroundColor[3]);
}
//=========================== /SETTERS =====================


void redraw(void){
  glutPostRedisplay();
}



//=========================== /EFECTS =====================

void activateFog(float fogColor[4], float density, float z0, float z1){
  // GLfloat fogColor[4] = {0.5f,0.5f,0.5f,1.0f};   // Fog Color
  glFogi(GL_FOG_MODE, GL_EXP2);       // Fog Mode GL_LINEAR GL_EXP GL_EXP2
  glFogfv(GL_FOG_COLOR, fogColor);               // Set Fog Color
  //glFogf(GL_FOG_DENSITY, 0.009f);                 // How Dense Will The Fog Be
  glFogf(GL_FOG_DENSITY, density);                 // How Dense Will The Fog Be
  glHint(GL_FOG_HINT, GL_DONT_CARE);             // Fog Hint Value
  //glFogf(GL_FOG_START, 1.0f);                    // Fog Start Depth
  //glFogf(GL_FOG_END, 0.0f);                      // Fog End Depth
  glFogf(GL_FOG_START, z0);                    // Fog Start Depth
  glFogf(GL_FOG_END, z1);                      // Fog End Depth
  glEnable(GL_FOG);                              // Enables GL_FOG

  setBackgroundColor(fogColor);

}

void deactivateFog(){
    glDisable(GL_FOG);
}
//=========================== /EFECTS =====================


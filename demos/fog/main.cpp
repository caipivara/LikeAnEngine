#include "LikeAnEngine.h"

void keyboard(){
  glutPostRedisplay();
  //If theres any change over an object must call redraw function
  if(keyboardManager->isPressed('+')){camera->moveCamFront(true); glutPostRedisplay();}
  if(keyboardManager->isPressed('-')){camera->moveCamFront(false); glutPostRedisplay();}
  if(keyboardManager->isPressed('s')){arrayModels[0].moveInX(false); glutPostRedisplay();}
  if(keyboardManager->isPressed('w')){arrayModels[0].moveInX(true); glutPostRedisplay();}
  if(keyboardManager->isPressed('d')){arrayModels[0].moveInZ(true); glutPostRedisplay();}
  if(keyboardManager->isPressed('a')){arrayModels[0].moveInZ(false); glutPostRedisplay();}
  if(keyboardManager->isPressed('q')){arrayModels[0].moveInY(false); glutPostRedisplay();}
  if(keyboardManager->isPressed('e')){arrayModels[0].moveInY(true); glutPostRedisplay();}

  if(keyboardManager->isPressed('k')){
    for(int i = 0; i < numLights;i++){arrayLights[i].moveInX(false);}
    glutPostRedisplay();
  }
  if(keyboardManager->isPressed('i')){
    for(int i = 0; i < numLights;i++){arrayLights[i].moveInX(true);}
    glutPostRedisplay();
  }
  if(keyboardManager->isPressed('l')){
    for(int i = 0; i < numLights;i++){arrayLights[i].moveInZ(true);}
    glutPostRedisplay();
  }
  if(keyboardManager->isPressed('j')){
    for(int i = 0; i < numLights;i++){arrayLights[i].moveInZ(false);}
    glutPostRedisplay();
  }
  if(keyboardManager->isPressed('u')){
    for(int i = 0; i < numLights;i++){arrayLights[i].moveInY(false);}
    glutPostRedisplay();
  }
  if(keyboardManager->isPressed('o')){
    for(int i = 0; i < numLights;i++){arrayLights[i].moveInY(true);}
    glutPostRedisplay();
  }

  if(keyboardManager->isPressed(GLUT_KEY_UP)){camera->orientAngleCam(false,false,true,false); glutPostRedisplay();}
  if(keyboardManager->isPressed(GLUT_KEY_DOWN)){camera->orientAngleCam(false,false,true,true); glutPostRedisplay();}
  if(keyboardManager->isPressed(GLUT_KEY_LEFT)){camera->orientAngleCam(true, false, false, false); glutPostRedisplay();}
  if(keyboardManager->isPressed(GLUT_KEY_RIGHT)){camera->orientAngleCam(true, true, false, false); glutPostRedisplay();}
}
//==============================================================================

//If I want to draw something by hand in opengl...
void mydisplay(){
  glPushMatrix();
    glBegin(GL_QUADS);
      glColor3f(1.0, 0.0, 0.0);
      glVertex3f(-200.0f, 0.0f, -200.0f);
      glColor3f(0.0, 1.0, 0.0);
      glVertex3f(-200.0f, 0.0f,  200.0f);
      glColor3f(0.0, 0.0, 1.0);
      glVertex3f( 200.0f, 0.0f,  200.0f);
      glColor3f(1.0, 1.0, 0.0);
      glVertex3f( 200.0f, 0.0f, -200.0f);
    glEnd();
  glPopMatrix();
}

int main(int argc, char** argv)
{
  initEngine(argc, argv, "Engine Test");

  setKeyboardFunc(keyboard);//To catch key events
  //setAditionalDisplayFunc(mydisplay);//To draw extra object

  //Create a fog
  GLfloat fogColor[4] = {0.5f,0.5f,0.5f,1.0f};   // Fog Color
  activateFog(fogColor, 0.009, 0.0, 1.0);
  //deactivateFog();

  startEngineLoop();
  return 0;
}



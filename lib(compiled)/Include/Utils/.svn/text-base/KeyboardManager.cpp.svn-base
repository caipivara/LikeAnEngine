/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  24 - September - 2009
*/

#include "KeyboardManager.h"

//Constructors ----------------------------------------------------------
KeyboardManager::KeyboardManager(){
  initValues();
}

void KeyboardManager::initValues(){
  for(int i = 0; i < 127; i++){ press[i] = false;}
  for(int i = 0; i < 108; i++){ specialPress[i] = false;}
}
//--------------------------------------------------------------------------

bool KeyboardManager::isPressed(const char key){
  return press[(int)key];
}

bool KeyboardManager::isPressed(const int key){
  return specialPress[(int)key];
}

void KeyboardManager::setPress(unsigned char key, bool pressed){
  press[(int)key] = pressed;
}

void KeyboardManager::setPress(const int key, bool pressed){
  specialPress[key] = pressed;
}

/*
  Written by: 
  Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  24 - September - 2009
*/

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

using namespace std;

/*
  This class manages the keyboards events,
  now when a key is pressed and when not
*/
class KeyboardManager{
 public:
  KeyboardManager();
  void initValues();
  
  //Says if the key is pressed
  bool isPressed(const char key);
  //Says if the especialKey key is pressed
  bool isPressed(const int key);

  //Set the press value to the key pressed 
  void setPress(unsigned char key, bool press);
  //Set the press value to the specialKey pressed 
  void setPress(int key, bool press);
  
 private:

  /* Each key correspond with her ASCCI char value in the array
  For the normal keys */
  bool press[127];
   /* Each key correspond with her int value for GLUT library in the array
  For the special keys */
  bool specialPress[108];
  
};

#endif 

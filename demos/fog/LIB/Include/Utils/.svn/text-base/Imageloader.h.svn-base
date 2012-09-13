/*
  
  Modified by: Daniel Gomez Rico
  danielgomezrico@gmail.com   
  Student of system engineering, 6 semester
  at the EAFIT university from Colombia
  14 - August - 2009
  
  Original file:
  File for "Textures" lesson of the OpenGL tutorial on
  www.videotutorialsrock.com
  
*/


#ifndef IMAGE_LOADER_H_INCLUDED
#define IMAGE_LOADER_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


//Represents an image
class Image {
 public:
  
  Image();
  Image(char* ps, int w, int h);
  ~Image();

  char* getPixels();
  int getWidth();
  int getHeight();

  void operator=(Image *newImage);
  /* An array of the form (R1, G1, B1, R2, G2, B2, ...) indicating the
   * color of each pixel in image.  Color components range from 0 to 255.
   * The array starts the bottom-left pixel, then moves right to the end
   * of the row, then moves up to the next column, and so on.  This is the
   * format in which OpenGL likes images.
   */
 private:
  char* pixels;
  int width;
  int height;
};

//Reads a bitmap image from file.
Image* loadBMP(const char* filename);
//Load a .RAW format image and returns the Image with it
Image* loadRAW(int width ,int height, const char * filename);


//Returns an array with all the glTextureEnvMode by default GL_MODULATE
GLuint* getGLTextureEnvMode(int size);

/*
  Set in texturesId the ids for each texture in images for the image
  numText is the number of textures to load
*/
void loadTextures(Image* images, GLuint *texturesId, GLuint * glTextureEnvMode,int numText);








#endif

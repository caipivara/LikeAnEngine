===========================================================================

			LIKE AN ENGINE
 	Open source graphics engine, for everyone!!!

===========================================================================


Like an engine is an open source graphics engine with gpl licence, 
written in c++ and opengl (with glut),
that encapsulates opengl for the user,

Now anyone with no knowledge about opengl CAN MAKE 3D COOL THINGS!!!!!

ex:
Say, i want a cube, in x,y position with this color…
cube move in this direction…
Load this .3ds model with this propertys…
Draw a sphere in this position… with this texture…


Developer: 
	Daniel Gòmez Rico, danielgomezrico@gmail.com
	12/02/2010


The thing now is imagination,

only imagination







---------------------------------------------------------
		HOW - TO COMPILE - RUN
---------------------------------------------------------

You must create:

1) WorldConf folder: it must have 3 things ALWAYS
	1) world.txt: file is described down...
	2) Textures folder: folder that contains the images of the textures
	3) Models folder: folder that contains the .3ds models

	Each one of this must exist always

2) Include the LikeAnEngine.h header in the files that will use the engine.

3) There are 3 principal functions to run the engine in this order:
	1) initEngine
	2) setKeyboardManager -> only if you want to manage the keys press or 
	unpress of the keyboard.
	3) startEngineLoop

- To compile, says to the compiler to use the libLikeAnEngine and the includes,
then : Enjoy!!!.


Compilation in code::blocks ide
----

Right click over the project, build options:

- Linker Settings: clic in add, and select the LibLikeAnEngine.so
- Search Directories: select add (in compiler) and select the includes 
		      directories.

then... RUN!!!



---------------------------------------------------------
			LICENCE
---------------------------------------------------------

This software is protected by GPL v3 licence, search COPYING.txt to se more.











---------------------------------------------------------
			REQUIREMENTS
---------------------------------------------------------

Glut - http://www.opengl.org/resources/libraries/glut/glut_downloads.php (in linux: $aptitude install freeglut3-dev)









---------------------------------------------------------
			CONF FILE
---------------------------------------------------------

In the WorldConf folder you can find the file "world.txt", that contents all the 
configurations for the scene

NOTE: you must define the limits and the textures BEFORE ALL always
WARNING: the file must not contain errors, loader dont check sintax errors, 
	EVERYTHING MUST BE COMPLETE.

How to define it:

-limits
Number-of-spheres
Number-of-planes
Number-of-cubes
Number-of-lights
Number-of-textures
Number-of-models

-textures
Name-of-texture-01
Name-of-texture-02
Name-of-texture-03
.
.
.

-camera
x y z deltaM upX upY upZ  theta beta deltaT deltaB

-plane 
v1-x v1-y v1-z   v2-x v2-y v2-z   v3-x v3-y v3-z    v4-x v4-y v4-z
x y z
r g b alpha            -> colosr
textureNumber    
tc0X tc0Y tc1X tc1Y    ->Text coords
tc2X tc2Y tc3X tc3Y

-model
name-of-model.3ds or .3DS
x y z
dx dy dz
r g b val              -> Ambiental-material
r g b val              -> Diffuse-material
r g b val              -> Specular-material

-sphere
x y z radius
r g b alpha            -> Color
r g b val              -> Ambiental-material
r g b val              -> Diffuse-material
r g b val              -> Specular-material
textureNumber


-cube
x y z side
r g b alpha             -> Color
r g b val               -> Ambiental-material
r g b val               -> Diffuse-material
r g b val               -> Specular-material
textureNumber

-light
x y z                   -> Position      
r g b val               -> Ambiental-light
r g b val               -> Diffuse-light
r g b val               -> Specular-light  
c l q                   -> Attenuation Constant Lineal Quadratic




In this version :

- Reads Models in format 3ds using l3ds.cpp file , but with some bugs, NO READS TEXTURE








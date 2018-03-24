READ ME file for this final

The following files have been modified here

Shapes.h

Create #define constants for the 3 models to be used when drawing them

Shapes.cpp

Contains a function to parse .obj files exported from Blender. The .obj files are used to represent the 3 models i.e -

wooden plane
Luxo
Sphere


The file contains methods to render these 3 models


Textures.cpp

Used to load the wood-floor .jpg image to texture map on the plane surface


textingMain.cpp

Buffer creation for 3 objects, calling the functions to create these shapes and in shaders for these
3 shapes.

The other files are as is and have been reused from previous labs, these include the phong and texture vertex,fragment shaders.

header.mak

Consists of an addition of -std=c++11

To run first create a makefile using gmakemake, type make and then ./textingMain

This was tested on Ubuntu 16.04.

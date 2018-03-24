//
//  Textures
//
//  Created by Warren R. Carithers 2016/11/22.
//  Based on code created by Joe Geigel on 1/23/13.
//  Copyright 2016 Rochester Institute of Technology.  All rights reserved.
//
//  Contributor:  YOUR_NAME_HERE
//
//  Simple class for setting up texture mapping parameters.
//
//  This code can be compiled as either C or C++.
//

#ifdef __cplusplus
#include <iostream>
#else
#include <stdio.h>
#endif

#include "Textures.h"

// this is here in case you are using SOIL;
// if you're not, it can be deleted.
#include <SOIL.h>
#include <string>

#ifdef __cplusplus
using namespace std;
#endif

// Add any global definitions and/or variables you need here.
GLuint wood_floor; 
GLint ambRefCoef; 
GLint diffRefCoef;
GLint specRefCoef;
GLint specExp;
GLint lightCol;
GLint lightPos;
GLint ambCol;
///
// This function loads texture data for the GPU.
//
// You will need to write this function, and maintain all of the values
// needed to be sent to the various shaders.
///
void loadTexture( void )
{
    // Add your code here.

   // This loads the Image into the texture
   // Since the bonus frowny image is also used
   // we have put two GLuint instances , one for smiley
   // and another for frowny 
   wood_floor = SOIL_load_OGL_texture( "wood-floor.jpg", 
         SOIL_LOAD_AUTO, 
         SOIL_CREATE_NEW_ID, 
         SOIL_FLAG_MIPMAPS |SOIL_FLAG_INVERT_Y|SOIL_FLAG_TEXTURE_REPEATS);


  //   	GLuint frowny = SOIL_load_OGL_texture( "frowny2.png",SOIL_LOAD_AUTO,
//			SOIL_CREATE_NEW_ID,SOIL_FLAG_MIPMAPS|SOIL_FLAG_INVERT_Y|SOIL_FLAG_TEXTURE_REPEATS);


	glActiveTexture(GL_TEXTURE0); //for first texture
	glBindTexture(GL_TEXTURE_2D, wood_floor);

//	glActiveTexture(GL_TEXTURE0+2); //for 2nd texture jump by 2
//	glBindTexture(GL_TEXTURE_2D, frowny);

}

///
// This function sets up the parameters for texture use.
//
// You will need to write this function, and maintain all of the values
// needed to be sent to the various shaders.
//
// @param program - The ID of an OpenGL (GLSL) shader program to which
//    parameter values are to be sent
///
void setUpTexture( GLuint program )
{
    // Add your code here.
	//declaring all the varibales needed

	
	// assign the values for the various
	// parameters of mapping and shading
 	// and send them to the shader to use.
	ambRefCoef = glGetUniformLocation(program, "ambRefCoef");
	diffRefCoef = glGetUniformLocation(program, "diffRefCoef");
	specRefCoef = glGetUniformLocation(program, "specRefCoef");
	specExp = glGetUniformLocation(program, "specExp");
	lightCol = glGetUniformLocation(program, "lightCol");
	lightPos = glGetUniformLocation(program, "lightPos");
	ambCol = glGetUniformLocation(program, "ambCol");


	glUniform1f(ambRefCoef, 0.5);
	glUniform1f(diffRefCoef, 0.7);
	glUniform1f(specRefCoef, 1.0);
	glUniform1f(specExp, 10.0);
	glUniform4f(lightCol, 1.0, 1.0, 0.0, 1.0 );
	glUniform4f(lightPos, 0.0, 5.0, 2.0, 1.0 );
	glUniform4f(ambCol, 0.5, 0.5, 0.5, 1.0);

   

   GLuint sample_loc = glGetUniformLocation(program, "wood_floor"); //read image data into 2D buffers
   //GLuint sample_loc_2 = glGetUniformLocation(program, "frowny_img");

   glUniform1i(sample_loc, 0); //texture 1 
   //glUniform1i(sample_loc_2, 2); //texture 2	 
}

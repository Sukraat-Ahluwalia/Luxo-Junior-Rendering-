//
//  Lighting
//
//  Created by Warren R. Carithers 2016/11/22.
//  Based on code created by Joe Geigel on 1/23/13.
//  Copyright 2016 Rochester Institute of Technology.  All rights reserved.
//
//  Contributor:  YOUR_NAME_NERE
//
//  Simple class for setting up Phong illumination/shading.
//
//  This code can be compiled as either C or C++.
//

#include "Lighting.h"

// Add any global definitions and/or variables you need here.

//GLint	ambMatCol;
//GLint	diffuseMatCol;
//GLint	specMatCol;
//GLint	ambRefCoef;
//GLint	diffRefCoef;
//GLint	specRefCoef;
//GLint	specExp;
//GLint	lightCol;
//GLint	lightPos;
//GLint	ambCol;
///
// This function sets up the lighting, material, and shading parameters
// for the Phong shader.
//
// You will need to write this function, and maintain all of the values
// needed to be sent to the vertex shader.
//
// @param program - The ID of an OpenGL (GLSL) shader program to which
//    parameter values are to be sent
///
void setUpPhong( GLuint program, float ambientMatColor[], float diffuseMatColor[],float specularMatColor[],float ambientRefColor,
		float diffuseRefCoef, float specularRefCoef,float specularExp,float lightColor[],float lightPosition[], float ambientColor[])
{
    // This is the phong shading setup method
   // It's job is to send data to the shaders

  // We will send the constants we declared in the
  // global scope above using OpenGL methods to the shaders

 
GLint	ambMatCol;
GLint	diffuseMatCol;
GLint	specMatCol;
GLint	ambRefCoef;
GLint	diffRefCoef;
GLint	specRefCoef;
GLint	specExp;
GLint	lightCol;
GLint	lightPos;
GLint	ambCol;

	

    // assigning values and send information to the vertex shader
	ambMatCol = glGetUniformLocation(program, "ambMatCol");
	diffuseMatCol = glGetUniformLocation(program, "diffuseMatCol");
	specMatCol = glGetUniformLocation(program, "specMatCol");
	ambRefCoef = glGetUniformLocation(program, "ambRefCoef");
	diffRefCoef = glGetUniformLocation(program, "diffRefCoef");
	specRefCoef = glGetUniformLocation(program, "specRefCoef");
	specExp = glGetUniformLocation(program, "specExp");
	lightCol = glGetUniformLocation(program, "lightCol");
	lightPos = glGetUniformLocation(program, "lightPos");
	ambCol = glGetUniformLocation(program, "ambCol");


	glUniform4f(ambMatCol, ambientMatColor[0],ambientMatColor[1],ambientMatColor[2],ambientMatColor[3]);
	glUniform4f(diffuseMatCol, diffuseMatColor[0],diffuseMatColor[1],diffuseMatColor[2],diffuseMatColor[3]);
	glUniform4f(specMatCol, specularMatColor[0],specularMatColor[1],specularMatColor[2],specularMatColor[3]);
	glUniform1f(ambRefCoef, ambientRefColor);
	glUniform1f(diffRefCoef,diffuseRefCoef);
	glUniform1f(specRefCoef, specularRefCoef);
	glUniform1f(specExp, specularExp);
	glUniform4f(lightCol, lightColor[0],lightColor[1],lightColor[2],lightColor[3]);
	glUniform4f(lightPos, lightPosition[0],lightPosition[1],lightPosition[2],lightPosition[3]);
	glUniform4f(ambCol, ambientColor[0],ambientColor[1],ambientColor[2],ambientColor[3]);


//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

}

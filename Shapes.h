//
// Shapes.h
//
// Prototypes for shape-drawing functions.
//
// This file should not be modified by students.
//

#ifndef _SHAPES_H_
#define _SHAPES_H_

#include "Canvas.h"

// Macros for object and shading selection
#define OBJ_plane	0
#define OBJ_luxo	1
#define OBJ_sphere	2
///
// Make either a quad or teapot
//
// @param choice - 0 for quad. 1 for teapot
// @param C      - the Canvas we'll use
///
void makeShape( int choice, Canvas &C );

#endif

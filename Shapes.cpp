//
// Shapes.cpp
//
// Routines for shape-drawing functions.
//
// This file should not be modified by students.
//

#include <cmath>
#include "Canvas.h"
#include "Shapes.h"
#include <iostream>
#include "Vertex.h"
#include <string>
#include <cstring>
#include <cstdio>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4

using namespace std;

/**
* These are global variables
* used for reading the vertices
* of the obj files where the models
* are and used to render in their
* respective make functions.
*/
vector<unsigned int> 		v_indices;
vector<unsigned	int>		n_indices;// uvIndices, 
vector< Vertex > 		t_vertices;
vector< Normal > 		t_normals;

/**
* This functions parses an obj file that
* represents a 3D model made in Blender
* and fills in the data needed to render
* those models.
*
* @params path the path of the .obj file
*
*Returns true or false depending on the success of the parse operation
*/
bool loadOBJ(const char * path){

	FILE *file = fopen(path, "r");
	if( file == NULL ){
		//fprintf("Impossible to open the file !\n");
    return false;
	}

	while( 1 ){

    char line[128];

    // read the first word of the line
    int res = fscanf(file, "%s", line);

    if (res == EOF)
        break; // EOF = End Of File. Quit the loop.

    // otherwise parse the line

	if ( strcmp( line, "v" ) == 0 ){
		Vertex vertex;
		fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
		t_vertices.push_back(vertex);

	}else if ( strcmp( line, "vn" ) == 0 ){
		Normal normal;
		fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
		t_normals.push_back(normal);

	}else if ( strcmp( line, "f" ) == 0 ){
		
		unsigned int v_index[3], n_index[3];
		int matches = fscanf(file, "%d//%d %d//%d %d//%d\n", &v_index[0],  &n_index[0], &v_index[1],  &n_index[1], &v_index[2],  &n_index[2] );
		if (matches != 6){
			printf("File can't be read by our simple parser : ( Try exporting with other options\n");
			return false;
    }
    v_indices.push_back(v_index[0]);
    v_indices.push_back(v_index[1]);
    v_indices.push_back(v_index[2]);
    n_indices.push_back(n_index[0]);
    n_indices.push_back(n_index[1]);
    n_indices.push_back(n_index[2]);
	}


	}//function ends here

}




//
// makeluxo() - create a luxo object
//
static void makeluxo( Canvas &C )
{
	//cout<<"entered luxo"<<endl;
	v_indices.clear();
	n_indices.clear();
	t_vertices.clear();
	t_normals.clear();

    	int i;
	bool result = loadOBJ("luxo.obj");

    	for( i = 0; i < v_indices.size() - 2; i += 3 ) {

        // Calculate the base indices of the three vertices
        int point1 = v_indices[i];     // slots 0, 1, 2
        int point2 = v_indices[i + 1]; // slots 3, 4, 5
        int point3 = v_indices[i + 2]; // slots 6, 7, 8

        Vertex p1 = t_vertices.at(point1-1);

        Vertex p2 = t_vertices.at(point2-1);

        Vertex p3 = t_vertices.at(point3-1);

        // Calculate the base indices of the three normals
        int normal1 = n_indices[i]; // slots 0, 1, 2
        int normal2 = n_indices[i + 1]; // slots 3, 4, 5
        int normal3 = n_indices[i + 2]; // slots 6, 7, 8

        Normal n1 = t_normals.at(normal1-1);

        Normal n2 = t_normals.at(normal2-1);

        Normal n3 = t_normals.at(normal3-1);

        // Add triangle and vertex normals
        C.addTriangleWithNorms( p1, n1, p2, n2, p3, n3 );

    }
}


// makeplane() - create a plane object
//
static void makeplane( Canvas &C )
{
    	v_indices.clear();
	n_indices.clear();
	t_vertices.clear();
	t_normals.clear();


    	int i;
	bool result = loadOBJ("plane.obj");

    	for( i = 0; i < v_indices.size() - 2; i += 3 ) {

        // Calculate the base indices of the three vertices
        int point1 = v_indices[i];     // slots 0, 1, 2
        int point2 = v_indices[i + 1]; // slots 3, 4, 5
  	int point3 = v_indices[i + 2];

        Vertex p1 = t_vertices.at(point1-1);
        Vertex p2 = t_vertices.at(point2-1);
        Vertex p3 = t_vertices.at(point3-1);
        // Calculate the base indices of the three normals
        int normal1 = n_indices[i];// slots 0, 1, 2
        int normal2 = n_indices[i + 1]; // slots 3, 4, 5
        int normal3 = n_indices[i + 2]; // slots 6, 7, 8

        Normal n1 = t_normals.at(normal1-1);

        Normal n2 = t_normals.at(normal2-1);

        Normal n3 = t_normals.at(normal3-1);

        // Add triangle and vertex normals
        C.addTriangleWithNorms( p1, n1, p2, n2, p3, n3 );

    }
}

//create a sphere oject
static void makesphere(Canvas &C)
{
	//cout<<"Enter sphere"<<'\n';
	v_indices.clear();
	n_indices.clear();
	t_vertices.clear();
	t_normals.clear();


    	int i;
	bool result = loadOBJ("sphere.obj");

    	for( i = 0; i < v_indices.size() - 2; i += 3 ) {

        // Calculate the base indices of the three vertices
        int point1 = v_indices[i];     // slots 0, 1, 2
        int point2 = v_indices[i + 1]; // slots 3, 4, 5
        int point3 = v_indices[i + 2]; // slots 6, 7, 8

        Vertex p1 = t_vertices.at(point1-1);

        Vertex p2 = t_vertices.at(point2-1);

        Vertex p3 = t_vertices.at(point3-1);

        // Calculate the base indices of the three normals
        int normal1 = n_indices[i]; // slots 0, 1, 2
        int normal2 = n_indices[i + 1]; // slots 3, 4, 5
        int normal3 = n_indices[i + 2]; // slots 6, 7, 8

        Normal n1 = t_normals.at(normal1-1);

        Normal n2 = t_normals.at(normal2-1);

        Normal n3 = t_normals.at(normal3-1);

        // Add triangle and vertex normals
        C.addTriangleWithNorms( p1, n1, p2, n2, p3, n3 );

    }
}

///
// Make either a plane or luxo
//
// @param choice - 0 for plane. 1 for luxo
// @param C      - the Canvas we'll use
///
void makeShape( int choice, Canvas &C )
{
    cout<<"choice:"<<choice<<'\n';
    if( choice == OBJ_plane ){
        makeplane( C );
    }

    if( choice == OBJ_luxo){
		//cout<<"Making luxo"<<endl;
	makeluxo(C);		
    }
 
    if( choice == OBJ_sphere){
       makesphere( C );
    }
}

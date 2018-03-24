#version 150

// Shader for texture mapping
// author: Sukraat Ahluwalia(sxa4430@rit.edu)


// INCOMING DATA
in vec2 texCoord;
in vec3 v;
in vec3 N;
in vec3 L;

//in vec4 vPosition;
//in vec3 vNormal;

// Here is where you should add the variables you need in order
// to propogate data from the vertex shader to the fragment shader
// so that it can do the shading and texture mapping computations

uniform sampler2D 	wood_floor;
uniform sampler2D	frownyImg;
uniform float	ambRefCoef;
uniform float	diffRefCoef;
uniform float	specRefCoef;
uniform float	specExp;
uniform vec4	lightCol;
uniform vec4	ambCol;


// OUTGOING DATA

out vec4 finalColor;

void main()
{
    // Replace this code with your implementation of this shader
    
    
    	vec3 Nv= normalize(N);
	vec3 Lv= normalize(L-v);
	vec3 E = normalize(-v);
	vec3 R = normalize(reflect(-Lv,Nv)); 

	vec3 Diffuse = vec3(diffRefCoef*max(dot(Nv,Lv), 0.0)*lightCol);
	vec3 Specular = vec3(specRefCoef * pow(max(dot(R,E), 0.0),specExp) * lightCol);
	vec3 Ambient = vec3(ambRefCoef * ambCol);
    
    
    vec4 color = vec4((Ambient + Specular + Diffuse), 1.0);
    
    
    if(gl_FrontFacing)
		{
			finalColor = color*texture(wood_floor, texCoord);
		}
	else 
		{
			finalColor = color*texture(frownyImg, texCoord);
		}
    
}

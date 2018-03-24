#version 150

// The Fragment Shader to do Phong Shading
// @author: Sukraat Ahluwalia(sxa4430@rit.edu)


//incoming data
in vec3 v;
in vec3 N;
in vec3 L;


//OUTGOING DATA
out vec4 finalColor;


//Other variables
uniform vec4	ambMatCol;
uniform	vec4	diffuseMatCol;
uniform	vec4	specMatCol;

uniform float	ambRefCoef;
uniform	float	diffRefCoef;
uniform	float	specRefCoef;
uniform	float	specExp;

uniform	vec4	lightCol;
uniform	vec4	ambCol;


void main()
{
	//Replace this code with your implementation of the shader

	vec3 Nv = normalize(N);
	vec3 Lv = normalize(L-v);
	vec3 E = normalize(-v);
	vec3 R = normalize(reflect(-Lv,Nv));

	vec4 Diffuse = vec4( diffuseMatCol * diffRefCoef * max( dot( Nv,Lv), 0.0) * lightCol);
	vec4 Specular = vec4( specMatCol * specRefCoef * pow( max(dot(R,E), 0.0), specExp) * lightCol);
	vec4 Ambient = vec4( ambMatCol * ambRefCoef * ambCol );


	finalColor = vec4( vec3(Ambient + Diffuse + Specular), 1.0 );
}




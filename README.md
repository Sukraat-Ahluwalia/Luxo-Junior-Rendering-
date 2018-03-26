# Luxo-Junior-Rendering-
Rendering Luxo Junior with some simple animations in OpenGL and C++ as part of my final project for my Computer Graphics course. The aim of the project is to render Luxo Jr. as close as possible to the original.

The original Luxo Jr. looks like this:

![Luxo Jr. Original](https://s3.envato.com/files/127881089/Pixar%20Luxo%20Jr%20Final%20Envato.jpg)

Building the code in this repository(assuming you have all the libraries needed for the code) and entering `./textingMain` on a terminal will lead to this rendering:

![Render](https://i.imgur.com/xxdqoVo.png)

Pressing `a` on the render will lead to a simple animation of the render being rotated.

Dependencies needed for the code: 

* OpenGL 4.5(or above)
* GLSL 3.0(or above)
* SOIL(Image loading library for OpenGL)

Typing `sudo apt-get install mesa-utils` on Ubuntu and then updating Nvidia/AMD drivers should take care of OpenGL and GLSL versions, for SOIL type `sudo apt-get install libsoil-dev`. Once that has been handled just type `make` and run `./textingMain` to render Luxo Jr.

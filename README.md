Zach Pedersen

My entry for CST-310 Project 5 - Rendering Scene with Primitives (Part 2).

To run the program:

Download the files BRM.cpp, Shader.h, shader.vert and shader.frag from the GitHub repository
Save them to the same directory and open that directory in the Ubuntu terminal
Use the following commands to run the program and display the scene: 'g++ -o BRM BRM.cpp -lGL -lGLU -lglut' './BRM'
Packages lGLFW, lGL and lX11 are used to run this program, which can be obtained by using command 'sudo apt-get install libGL-dev'

CAMERA CONTROLS:
w: up
s: down
a: left
d: right
i: zoom in
o: zoom out

POSITION CONTROLS:
j: up
n: down
b: left
m: right
l: move near
k: move far
q to move to default position (both eyepoint & lookat point)
f: to turn on/off fan

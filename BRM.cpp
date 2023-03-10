//Zach Pedersen
//This is my work
//Prof. Citro
//CST-310

#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

GLboolean redFlag = true, fanSwitch = false;
double windowHeight=800, windowWidth=600;
double eyeX=7.0, eyeY=2.0, eyeZ=15.0, refX = 0, refY=0,refZ=0;
double theta = 180.0, y = 1.36, z = 7.97888, a=2;

static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0}, //0
    {0.0, 0.0, 3.0}, //1
    {3.0, 0.0, 3.0}, //2
    {3.0, 0.0, 0.0}, //3
    {0.0, 3.0, 0.0}, //4
    {0.0, 3.0, 3.0}, //5
    {3.0, 3.0, 3.0}, //6
    {3.0, 3.0, 0.0}  //7
};

static GLubyte quadIndices[6][4] =
{
    {0, 1, 2, 3}, //bottom
    {4, 5, 6, 7}, //top
    {5, 1, 2, 6}, //front
    {0, 4, 7, 3}, // back is clockwise
    {2, 3, 7, 6}, //right
    {1, 5, 4, 0}  //left is clockwise
};


static GLfloat colors[6][3] =
{
    {0.4, 0.1, 0.0}, //bottom
    {0.6, 0.0, 0.7}, //top
    {0.0, 1.0, 0.0},
    {0.0, 1.0, 1.0},
    {0.8, 0.0, 0.0},
    {0.3, 0.6, 0.7}
};



void drawCube()
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
    }
    glEnd();
}

static GLfloat v_pyramid[5][3] =
{
    {0.0, 0.0, 0.0},
    {0.0, 0.0, 2.0},
    {2.0, 0.0, 2.0},
    {2.0, 0.0, 0.0},
    {1.0, 4.0, 1.0}
};

static GLubyte p_Indices[4][3] =
{
    {4, 1, 2},
    {4, 2, 3},
    {4, 3, 0},
    {4, 0, 1}
};

static GLubyte PquadIndices[1][4] =
{
    {0, 3, 2, 1}
};

void drawpyramid()
{
    glBegin(GL_TRIANGLES);
    for (GLint i = 0; i <4; i++)
    {
        glVertex3fv(&v_pyramid[p_Indices[i][0]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][1]][0]);
        glVertex3fv(&v_pyramid[p_Indices[i][2]][0]);
    }
    glEnd();

    glBegin(GL_QUADS);
    for (GLint i = 0; i <1; i++)
    {
        glVertex3fv(&v_pyramid[PquadIndices[i][0]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][1]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][2]][0]);
        glVertex3fv(&v_pyramid[PquadIndices[i][3]][0]);
    }
    glEnd();

}

void polygon()
{
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(6,0);
    glVertex2f(5.8,1);
    glVertex2f(5.2,2);
    glVertex2f(5, 2.2);
    glVertex2f(4, 2.8);
    glVertex2f(3,3);
    glVertex2f(2, 2.8);
    glVertex2f(1, 2.2);
    glVertex2f(0.8, 2);
    glVertex2f(0.2,1);
    //glVertex2f(0,0);
    
    glEnd();
}

void polygonLine()
{
    glBegin(GL_LINE_STRIP);
    //glVertex2f(0,0);
    glVertex2f(6,0);
    glVertex2f(5.8,1);
    glVertex2f(5.2,2);
   glVertex2f(5, 2.2);
    glVertex2f(4, 2.8);
    glVertex2f(3,3);
    glVertex2f(2, 2.8);
    glVertex2f(1, 2.2);
    glVertex2f(0.8, 2);
    glVertex2f(0.2,1);
    glVertex2f(0,0);
    
    glEnd();
}

void bedsideTable()
{
    //bedside drawer *************************************
      
      //side drawer
      glColor3f(0.2,0.1,0.1); //0.5,0.2,0.2
      glPushMatrix();
      glTranslatef(0.5,-0.1,8.7); //0.5,-0.1,9
      //glRotatef(22, 0,0,1);
      glScalef(0.12, 0.2, 0.23);
      drawCube();
      glPopMatrix();
      
      //side drawer's drawer
      glColor3f(0.3,0.2,0.2);
      glPushMatrix();
      glTranslatef(0.88,0,8.8);
      //glRotatef(22, 0,0,1);
      glScalef(0.0001, 0.11, 0.18);
      drawCube();
      glPopMatrix();
}

void bed()
{
    //bed headboard
    glColor3f(1.0,0.5,0.0);
    glPushMatrix();
    glScalef(0.1, 0.5, 0.9);
    glTranslatef(-2,-0.5,6);
    drawCube();
    glPopMatrix();
    
    //bed body
    glColor3f(0.824, 0.706, 0.549);
    glPushMatrix();
    glScalef(1, 0.2, 0.9); //1, 0.2, 0.9
    glTranslatef(0,-0.5,6.2);
    drawCube();
    glPopMatrix();
    
    //pillow right far
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(0.5,0.5,6);
    glRotatef(20, 0,0,1);
    glScalef(0.1, 0.15, 0.28);
    drawCube();
    glPopMatrix();
    
    //pillow left near
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(0.5,0.5,7.2);
    glRotatef(22, 0,0,1);
    glScalef(0.1, 0.15, 0.28);
    drawCube();
    glPopMatrix();
    
    //blanket
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(1.4,0.45,5.5);
    //glRotatef(22, 0,0,1);
    glScalef(0.5, 0.05, 0.95);
    drawCube();
    glPopMatrix();
    
    //blanket side left part
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(1.4,-0.3,8.15);
    //glRotatef(22, 0,0,1);
    glScalef(0.5, 0.25, 0.05);
    drawCube();
    glPopMatrix();
    
}

void lamp()
{
    //Lamp *****************************************
        
        //lamp base
        glColor3f(0.6, 0.6, 0.6);
        glPushMatrix();
        glTranslatef(.6,0.5,9.1);
        glScalef(0.07, 0.02, 0.07);
        drawCube();
        glPopMatrix();
        
        //lamp stand
        glColor3f(0.4, 0.4, 0.4);
        glPushMatrix();
        glTranslatef(.7,0.35,9.2);
        glScalef(0.01, 0.2, 0.01);
        drawCube();
        glPopMatrix();
        
        //lamp shade
        glColor3f(0.6, 0.6, 0.6);
        glPushMatrix();
        glTranslatef(.7,0.9,9.2);
        glScalef(0.08, 0.09, 0.08);
        drawCube();
        glPopMatrix();
        
}

void base()
{
    // right wall
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(-1.5,-1,.5);
    glScalef(5, 2, 0.1);
    drawCube();
    glPopMatrix();
    
    // left wall
    glColor3f(0.8, 0.8, 0.8);
    glPushMatrix();
    glTranslatef(-4.5,-1,0);
    glScalef(1, 2, 5);
    drawCube();
    glPopMatrix();
    
   //ceiling
    glColor3f(1.0, 0.9, 0.8);
    glPushMatrix();
    //glScalef(5, 0.1, 7);
    glTranslatef(-2,5.1,0);
    glScalef(5, 0.1, 7);
    drawCube();
    glPopMatrix();
    
    // carpet
    glColor3f(0.0, 0.5, 0.5);
    glPushMatrix();
    //glScalef(5, 0.1, 7);
    glTranslatef(3,-0.2,7);
    glScalef(1.3, 0.01, 1.7);
    drawCube();
    glPopMatrix();


      // floor
      glColor3f(0.5, 0.1, 0.0);
      glPushMatrix();
      glScalef(5, 0.1, 7);
      glTranslatef(-1,-5,0); //-1,-5,.5
      //glScalef(5, 0.1, 7);
      drawCube();
      glPopMatrix();
}

void Curtain()
{
    
    //Curtain
    glColor3f(0.0,0.1,0.1);
    glPushMatrix();
    glTranslatef(-0.5,2,9.5);
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, .3, .17);
    drawCube();
    glPopMatrix();
 }

void fan()
{
    glPushMatrix();
    glTranslatef(3,1.4,5);
    
    //fan cube
    glColor3f(0,0,0);
    glPushMatrix();
    glScalef(0.1,0.05,0.1);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();
    
    glPushMatrix();
    glRotatef(a, 0,1,0);
    
    //blade 1 blue
    glColor3f(0,0,0);
    glPushMatrix();
    //glRotatef(a, 0,1,0);
    glScalef(0.5,0.01,0.1);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();
    
    //blade 2 purple
    glColor3f(0,0,0);
    glPushMatrix();
    //glRotatef(a, 0,1,0);
    glScalef(0.1,0.01,0.5);
    glTranslatef(-1.5,-1.5,-1.5);
    drawCube();
    glPopMatrix();
    
    glPopMatrix();
    
    glPopMatrix();
}

void window()
{
    //Window ********************************************
    
    //window white open
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glTranslatef(-0.9,1,8.9); //0.5,1,9.6
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, .6, .3);
    drawCube();
    glPopMatrix();
    
    //window side corner
    glColor3f(0.8,0.6,0.4);
    glPushMatrix();
    glTranslatef(-0.9,1,8.9);
    //glRotatef(22, 0,0,1);
    glScalef(0.04, 0.6, 0.0001);
    drawCube();
    glPopMatrix();
    
    //window left side corner
    glColor3f(0.8,0.6,0.4);
    glPushMatrix();
    glTranslatef(-0.9,1,9.8);
    glScalef(0.04, 0.6, 0.0001);
    drawCube();
    glPopMatrix();
    
    //window upper side corner
    glColor3f(0.7,0.6,0.5);
    glPushMatrix();
    glTranslatef(-0.7,2.7,8.9);
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, 0.05, 0.4);
    drawCube();
    glPopMatrix();
    
    
    //window lower side corner
    glColor3f(0.7,0.6,0.5);
    glPushMatrix();
    glTranslatef(-0.8,1.02,8.9);
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, 0.02, 0.34);
    drawCube();
    glPopMatrix();
    
    //window vertical bar 1
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(-0.87,2.1,8.9);
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, 0.02, 0.3);
    drawCube();
    glPopMatrix();
    
    //window vertical bar 2
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(-0.87,1.6,8.9);
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, 0.02, 0.3);
    drawCube();
    glPopMatrix();
    
    //window horizontal bar
    glColor3f(0.0,0.0,0.0);
    glPushMatrix();
    glTranslatef(-0.87,1,9.3);
    //glRotatef(22, 0,0,1);
    glScalef(0.0001, 0.6, 0.02);
    drawCube();
    glPopMatrix();
}


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective(60,1,1,100);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ,  refX,refY,refZ,  0,1,0); //7,2,15, 0,0,0, 0,1,0

    glViewport(0, 0, 800, 600);
    
    base();
    bedsideTable();
    bed();
    lamp();
    window();
    fan();
    Curtain();

    glFlush();
    glutSwapBuffers();
}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
    case 'w': // move eye point upwards along Y axis
        eyeY+=1.0;
        break;
    case 's': // move eye point downwards along Y axis
        eyeY-=1.0;
        break;
    case 'a': // move eye point left along X axis
        eyeX-=1.0;
        break;
    case 'd': // move eye point right along X axis
        eyeX+=1.0;
        break;
    case 'o':  //zoom out
        eyeZ+=1;
        break;
    case 'i': //zoom in
        eyeZ-=1;
        break;
    case 'q': //back to default eye point and ref point
            eyeX=7.0; eyeY=2.0; eyeZ=15.0;
            refX=0.0; refY=0.0; refZ=0.0;
        break;
    case 'j': // move ref point upwards along Y axis
        refY+=1.0;
        break;
    case 'n': // move ref point downwards along Y axis
        refY-=1.0;
        break;
    case 'b': // move ref point left along X axis
        refX-=1.0;
        break;
    case 'm': // move eye point right along X axis
        refX+=1.0;
        break;
    case 'k':  //move ref point away from screen/ along z axis
        refZ+=1;
        break;
    case 'l': //move ref point towards screen/ along z axis
        refZ-=1;
        break;
        case 'f': //turn on/off fan
            if(fanSwitch == false) {
                fanSwitch = true; break;
            }
            else{
                fanSwitch = false; break;
            }
    case 27:    // Escape key
        exit(1);
    }
    
    glutPostRedisplay();
}


void animate()
{
    if(redFlag == true)
    {
        theta+=2;
        z-=0.02; //0.016667;
        if(theta >= 196 && theta <= 210)
        {
            y = 1.44;
        }
        else if(theta >= 180 && theta <= 194)
        {
            y = 1.42;
        }
        else if(theta >= 180 && theta <= 194)
        {
            y = 1.4;
        }
        else if(theta >= 164 && theta <= 178)
        {
            y = 1.42;
        }
        
        if(theta == 210)
        {
            redFlag = false;
        }
    }
    else if(redFlag == false)
    {
        theta-=2;
        z+=0.02;//0.016667;
        
        if(theta >= 196 && theta <= 210)
        {
            y = 1.44;
        }
        else if(theta >= 180 && theta <= 194)
        {
            y = 1.42;
        }
        else if(theta >= 180 && theta <= 194)
        {
            y = 1.4;
        }
        else if(theta >= 164 && theta <= 178)
        {
            y = 1.42;
        }
        
        if(theta == 150)
        {
            redFlag = true;
        }
    }
    
    if(fanSwitch == true){
    a+= 5;
            if(a > 360)
                a -= 360;
    }
    else{
        a = a;
    }
    
    glutPostRedisplay();

}

void assignment()
{
    
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    
    std::cout<<"To move Eye point:"<< std::endl;
    std::cout<<"w: up"<<std::endl;
    std::cout<<"s: down"<<std::endl;
    std::cout<<"a: left"<<std::endl;
    std::cout<<"d: right"<<std::endl;
    std::cout<<"i: zoom in"<<std::endl;
    std::cout<<"o: zoom out"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"To move Camera point:"<< std::endl;
    std::cout<<"j: up"<<std::endl;
    std::cout<<"n: down"<<std::endl;
    std::cout<<"b: left"<<std::endl;
    std::cout<<"m: right"<<std::endl;
    std::cout<<"l: move nearer"<<std::endl;
    std::cout<<"k: move far"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"Press q to move to default position"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"f: to turn on/off fan     "<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"____________________"<<std::endl;
    std::cout<<"      "<<std::endl;
    std::cout<<"      "<<std::endl;
    
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(windowHeight, windowWidth);
    glutCreateWindow("Bedroom");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    //glEnable(GL_NORMALIZE);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboardFunc);
    //glutSpecialFunc(myKeyboardFunc);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}

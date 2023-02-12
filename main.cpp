#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "ObjLoader.h"

using namespace std;

object bone;

int X, Y;
GLfloat eyeX, eyeY, eyeZ;
GLfloat trees [9][2] = {{150,150},{-150,100},{350,-140},{450,240},{600,-540},{480,640},{-250,600},{-480,640},{250,-600}};

void init(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 0, 0);  

  // set camera position
  eyeX = 0;
  eyeY = -15;
  eyeZ = 400;

  // enable changing material color
  glEnable (GL_TEXTURE_2D);
  glEnable(GL_COLOR_MATERIAL);
  // enable lighting
  glEnable(GL_LIGHTING);  
  glEnable(GL_LIGHT0);

  glEnable(GL_DEPTH_TEST);
}

void set_light(){
  // data structure for lights
  GLfloat ambient_light[] = {0.2, 0.2, 0.2, 1.0};
  GLfloat diffuse_light[] = {1.0, 1.0, 1.0, 1.0};
  GLfloat specular_light[] = {0.0, 1.0, 1.0, 1.0};
  GLfloat light_emission[] = {0.0, 0.7, 0.1, 0.0};
  GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};

  // define light parameters
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light); 
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light );
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light );
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

}

void reshape(int w, int h){
  float aspect = (float)w / (float)h;

  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // specify projection perspective
  gluPerspective(45.0,aspect,0.4,5000);

  // init model coordinate system
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawSky(){

  glPushMatrix();
    glColor3f(0.0f, 0.0f, 2.0f);
    gluSphere(gluNewQuadric(), 980, 50, 25);
  glPopMatrix(); 

}

void drawGround(){
  glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glPushMatrix();
    glRotatef(90,1,0,0);
    glTranslatef(0,0,23);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
      glVertex3f(1000, 1000, 100);
      glVertex3f(-1000, 1000, 100);
      glVertex3f(-1000, -1000, 100);
      glVertex3f(1000, -1000, 100);
    glEnd();
  glPopMatrix();
}

void drawTree(int x, int z){
  // tronco da árvore
    glPushMatrix();
      glTranslatef(x, -124, -z);
      glColor3f(0.3f, 0.2f, 0.0f);
      glRotatef(270, 1, 0, 0);
      gluCylinder(gluNewQuadric(), 5, 0, 120, 20, 20);
    glPopMatrix(); 

    // cone 1 da arvore 
    glColor3f(0.0f, 1.0f, 0.1f);
    glPushMatrix();
      glTranslatef(x, -40, -z);
      glRotatef(270, 1, 0, 0);
      gluCylinder(gluNewQuadric(), 25, 0, 40, 20, 20);
    glPopMatrix(); 

    // cone 2 da arvore 
    glColor3f(0.0f, 0.7f, 0.0f);
    glPushMatrix();
      glTranslatef(x, -65, -z);
      glRotatef(270, 1, 0, 0);
      gluCylinder(gluNewQuadric(), 40, 0, 40, 20, 20);
    glPopMatrix(); 

    // cone 3 da arvore 
    glColor3f(0.0f, 0.55f, 0.0f);
    glPushMatrix();
      glTranslatef(x, -90, -z);
      glRotatef(270, 1, 0, 0);
      gluCylinder(gluNewQuadric(), 55, 0, 40, 20, 20);
    glPopMatrix(); 
}

void drawEyes(int x){
  glColor3f(0.5f, 0.5f, 0.5f); // set eye color
  glPushMatrix(); 
    glTranslatef(x, 4, 10); // floatX, floatY, floatZ
    gluSphere(gluNewQuadric(), 3, 25, 25); //Specifies the quadrics object, radius, subdivisions around the z axis, subdivisions along the z axis
  glPopMatrix();

}

void drawButton(int y, int z){
  glColor3f(0.0f, 0.0f, 0.0f);
  glPushMatrix();
    glPushMatrix();
    glTranslatef(0, y, z);
    gluSphere(gluNewQuadric(), 2, 25, 25);
  glPopMatrix();
}

void drawSnowman(){

   // HEAD
    // has eyes and nose inside the head 
    glPushMatrix();
      glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef(0, -15, 0);
      gluSphere(gluNewQuadric(), 15, 25, 25);

      //EYES
      drawEyes(8); //right eye
      drawEyes(-8); // left eye

      // glColor3f(0.5f, 0.5f, 0.5f); // set eye color
      // glPushMatrix(); //right eye
      //   glTranslatef(8, 4, 12); // floatX, floatY, floatZ
      //   gluSphere(gluNewQuadric(), 3, 25, 25); //Specifies the quadrics object, radius, subdivisions around the z axis, subdivisions along the z axis
      // glPopMatrix();

      // glPushMatrix(); //left eye
      //   glTranslatef(-8, 4, 12);
      //   gluSphere(gluNewQuadric(), 3, 25, 25);
      // glPopMatrix();  
       
      //NOSE
      glColor3f(1.0f, 0.5f, 0.0f);
      glPushMatrix();
        glTranslatef(0, 0, 13);
        glutSolidCone(3, 15, 100, 25); // radius of the base, height, ubdivisions around the Z axis, subdivisions along the Z axis
      glPopMatrix();
    
    glPopMatrix();

    //SCARF
    // a red scarf
    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix();
      glTranslatef(0, -28, 0);
       glRotatef(90, 1.0, 0.0, 0.0);
       glutSolidTorus(6, 10, 20, 50);
    glPopMatrix();
    // base scarf
    glPushMatrix();
      glTranslatef(10, -42, 6);
       glRotatef(90, 0.0, 1.0, 0.0);
       glutSolidTorus(6, 10, 20, 50);
    glPopMatrix();
    

    // HAT
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix(); // base of hat
      //glTranslatef(0, 0, 0);
      glRotatef(90, 1.0, 0.0, 0.0);
      glutSolidTorus(5, 13, 20, 20); 
    glPopMatrix();

    glPushMatrix(); // hat body
        glTranslatef(0, 3, 0);
        glRotatef(180, 0.0, 10.0, 10.0); // angle, floatX, floatY, floatZ

        gluCylinder(gluNewQuadric(), 10, 10, 20, 20, 20); // quadrics object, base radius, top radius, heigth, slices, stacks
      glPopMatrix();

    glColor3f(1.0f, 0.0f, 0.0f);
    glPushMatrix(); // red
        glTranslatef(0, 3, 0);
        glRotatef(180, 0.0, 10.0, 10.0); // angle, floatX, floatY, floatZ
        gluCylinder(gluNewQuadric(), 10.5, 10, 5, 20, 20); // quadrics object, base radius, top radius, heigth, slices, stacks
    glPopMatrix();

  glColor3f(0.2f, 0.2f, 0.2f);
  // tampa do chapeu
  glPushMatrix(); 
        glTranslatef(0, 23, 0);
        glRotatef(180, 0.0, 10.0, 10.0); 
        gluDisk(gluNewQuadric(), 0, 10, 90, 1); 
    glPopMatrix(); 

    // BODY
    // has the buttons and arms inside
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
      glTranslatef(0, -48, 0);
      gluSphere(gluNewQuadric(), 25, 25, 25);

      //BUTTON
      // three black buttons

      drawButton(10, 23); // first button
      drawButton(0, 25); // middle button
      drawButton(-10, 23); // last button

      // ARMS
      glColor3f(0.2f, 0.0f, 0.0f);
      
      glPushMatrix();
        glTranslatef(20, 0, 0);
        glRotatef(75, -3.0, 10.0, 0.0); // angle, floatX, floatY, floatZ
        gluCylinder(gluNewQuadric(), 2, 2, 30, 20, 20); // quadrics object, base radius, top radius, heigth, slices, stacks
      glPopMatrix();

      glPushMatrix();
        glTranslatef(-50, 10, 0);
        glRotatef(90, 3.0, 10.0, 0.0);
        gluCylinder(gluNewQuadric(), 2, 2, 30, 20, 20);
      glPopMatrix();

      // LEGS
      glColor3f(1.0f, 1.0f, 1.0f);
      glTranslatef(0, -45, 0);
      gluSphere(gluNewQuadric(), 30, 25, 25);

    glPopMatrix();   

}

void draw(){


    cout << *bone.faces[1].v << endl;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(eyeX,eyeY,eyeZ,0,-15,0,0,1,0);

    int *x = bone.faces[10].v;

    cout << *x << endl;


    glRotatef(X, 1,0,0);
    glRotatef(Y, 0,1,0);
    set_light();

    //SglPushMatrix();

    drawSky();
    drawGround();
    
    //drawTrees
    for (int i = 0; i < 9; i++){
        drawTree(trees[i][0], trees[i][1]);
    }

    drawSnowman();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y){
    if (key == GLUT_KEY_RIGHT)
        Y += 5;
  //  Left arrow - decrease rotation by 5 degree
    else if (key == GLUT_KEY_LEFT){
        Y -= 5;
    }
    else if (key == GLUT_KEY_UP){
        X += 5;
    }
    else if (key == GLUT_KEY_DOWN){
        X -= 5;
    }
    else if(key == GLUT_KEY_F1){ //zoom-out
      eyeZ += 5;
    }
    else if(key == GLUT_KEY_F2){ //zoom-in
      if(eyeZ > 5){
        eyeZ -= 5;
      }
    }

    //  Request display update
    glutPostRedisplay();
}


int main(int argc, char **argv){
  // object bone;
  ObjLoader readModel;
  readModel.loadModel(bone,"3DModel.obj");

  glutInit(&argc, argv);
  // 
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(200, 100);
  glutInitWindowSize(1080, 720);
  glutCreateWindow("Snowman");

  init();

  glutDisplayFunc(draw);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
}

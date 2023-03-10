#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "ObjLoader.h"

using namespace std;

object bone;

int X, Y;
GLfloat paralax;
GLfloat distancia;

GLfloat eyeX, eyeY, eyeZ;

void init(){


  // set camera position
  eyeX = 0;
  eyeY = 0;
  eyeZ = 12;

  //set paralax
  paralax = -10.48;
  distancia = 0.05;

  // enable changing material color
  glEnable (GL_TEXTURE_2D);
  glEnable(GL_COLOR_MATERIAL);
  // enable lighting
  glEnable(GL_LIGHTING);  
  glEnable(GL_LIGHT0);

  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
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
  gluPerspective(10.0,aspect,0.4,5000);

  // init model coordinate system
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void drawR(){
   // glTranslatef(-0.09f,0,0);

    //glRotatef(X, 1,0,0);
    glRotatef(Y, 0,1,0);
    glTranslatef(-4.20f - distancia,-7.25,16);

    glColorMask(1,0,0,0.75);
    glBegin(GL_TRIANGLES);
      for(int i = 0; i < bone.faces.size(); i++){
        //cout << bone.vertices[*bone.faces[i].v].x << bone.vertices[*bone.faces[i].v].y << bone.vertices[*bone.faces[i].v].z << endl;
        glNormal3f(bone.normais[bone.faces[i].vn[0] -1].x ,bone.normais[bone.faces[i].vn[0] - 1].y, bone.normais[bone.faces[i].vn[0] - 1].z);
        glVertex3f(bone.vertices[bone.faces[i].v[0] -1].x, bone.vertices[bone.faces[i].v[0] - 1].y, bone.vertices[bone.faces[i].v[0] -1].z);

        glNormal3f(bone.normais[bone.faces[i].vn[1] -1].x ,bone.normais[bone.faces[i].vn[1] - 1].y, bone.normais[bone.faces[i].vn[1] - 1].z);
        glVertex3f(bone.vertices[bone.faces[i].v[1] -1].x, bone.vertices[bone.faces[i].v[1] - 1].y, bone.vertices[bone.faces[i].v[1] -1].z);

        glNormal3f(bone.normais[bone.faces[i].vn[2] -1].x ,bone.normais[bone.faces[i].vn[2] - 1].y, bone.normais[bone.faces[i].vn[2] - 1].z);
        glVertex3f(bone.vertices[bone.faces[i].v[2] -1].x, bone.vertices[bone.faces[i].v[2] - 1].y, bone.vertices[bone.faces[i].v[2] - 1].z);
      }
    glEnd();
   glTranslatef(4.20f,7.25,-16);
}
void drawL(){
    glRotatef(paralax, 0,1,0);
   
    glTranslatef(-4.20f + distancia,-7.25,16);

    glColorMask(0,0,1,1);
    glBegin(GL_TRIANGLES);
      for(int i = 0; i < bone.faces.size(); i++){
        //cout << bone.vertices[*bone.faces[i].v].x << bone.vertices[*bone.faces[i].v].y << bone.vertices[*bone.faces[i].v].z << endl;
        glNormal3f(bone.normais[bone.faces[i].vn[0] -1].x ,bone.normais[bone.faces[i].vn[0] - 1].y, bone.normais[bone.faces[i].vn[0] - 1].z);
        glVertex3f(bone.vertices[bone.faces[i].v[0] -1].x, bone.vertices[bone.faces[i].v[0] - 1].y, bone.vertices[bone.faces[i].v[0] -1].z);

        glNormal3f(bone.normais[bone.faces[i].vn[1] -1].x ,bone.normais[bone.faces[i].vn[1] - 1].y, bone.normais[bone.faces[i].vn[1] - 1].z);
        glVertex3f(bone.vertices[bone.faces[i].v[1] -1].x, bone.vertices[bone.faces[i].v[1] - 1].y, bone.vertices[bone.faces[i].v[1] -1].z);

        glNormal3f(bone.normais[bone.faces[i].vn[2] -1].x ,bone.normais[bone.faces[i].vn[2] - 1].y, bone.normais[bone.faces[i].vn[2] - 1].z);
        glVertex3f(bone.vertices[bone.faces[i].v[2] -1].x, bone.vertices[bone.faces[i].v[2] - 1].y, bone.vertices[bone.faces[i].v[2] - 1].z);
      }
    glEnd();
    //glTranslatef(-0.09f,0,0);
}

void draw(){
  glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
  glDepthMask (GL_TRUE);
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    //glClearColor(1,1,1,1);

    gluLookAt(eyeX,eyeY,eyeZ,0,0,0,0,1,0);

    cout << " eyeX:" << eyeX << " eyeY:" << eyeY <<" eyeZ:" << eyeZ << endl;
    cout << " RotateX:" << X << " RotateY:" << Y << endl;
    cout << "distancia: " << distancia << endl;
    cout << "paralax: " << paralax << endl;


  //  set_light();

    drawR();

		glClear(GL_DEPTH_BUFFER_BIT);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE, GL_ONE);

    drawL();

    //glDisable(GL_BLEND);

    //glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glutSwapBuffers();
    glDisable(GL_BLEND);
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
      eyeZ += 0.25;
    }
    else if(key == GLUT_KEY_F2){ //zoom-in

        eyeZ -= 0.25;
    }
    else if(key == GLUT_KEY_F3){ //paralax-in
        paralax += 0.05;
    }
    else if(key == GLUT_KEY_F4){ //paralax-out
        paralax -= 0.05;
    }
    else if(key == GLUT_KEY_F5){ //paralax-in
        distancia += 0.01;
    }
    else if(key == GLUT_KEY_F6){ //paralax-out
        distancia -= 0.01;
    }

    //  Request display update
    glutPostRedisplay();
}


int main(int argc, char **argv){
  ObjLoader readModel;
  readModel.loadModel(bone,"3DModel.obj");

  glutInit(&argc, argv);
  // 
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowPosition(200, 100);
  glutInitWindowSize(1080, 720);
  glutCreateWindow("femur");

  init();

  glutDisplayFunc(draw);
  glutReshapeFunc(reshape);
  glutSpecialFunc(specialKeys);
  glutMainLoop();
}

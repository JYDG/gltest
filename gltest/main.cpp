//
//  main.cpp
//  gltest
//
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

//#include "hw5.h"

using namespace std;

static int win = 0;

//정점의 좌표
GLfloat MyVertices[8][3] = {
    {-0.25, -0.25, 0.25},
    {-0.25, 0.25, 0.25},
    {0.25, 0.25, 0.25},
    {0.25, -0.25, 0.25},
    {-0.25, -0.25, -0.25},
    {-0.25, 0.25, -0.25},
    {0.25, 0.25, -0.25},
    {0.25, -0.25, -0.25}
};

//정점의 색
GLfloat MyColors[8][3] = {
    {0.2, 0.2, 0.2},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0}
};

//6개의 면
GLubyte MyVertexList[24] = {
    0,3,2,1,
    2,3,7,6,
    0,4,7,3,
    1,2,6,5,
    4,5,6,7,
    0,1,5,4
};

void CreateGlutWindow() {
//    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitDisplayMode (GLUT_RGB);
    glutSwapBuffers();
    glutInitWindowPosition (10, 10);
    glutInitWindowSize (512, 512);
    win = glutCreateWindow ("OpenGL Test");
}

void InitOpenGL() {
    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(90.0, 1.0, 0.1, 100);
//    glMatrixMode(GL_MODELVIEW);
//    
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_TEXTURE_2D);
//    
//    glEnable(GL_NORMALIZE);
//    glShadeModel(GL_SMOOTH);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    //표면을 반시계 방향 순서로 나열하겠다
    glFrontFace(GL_CCW);
    
    //보이지않는 면은 제거
    glEnable(GL_CULL_FACE);
    
    //정점 배열 기능 활성화
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    //실제정점좌표를 저장한 변수명을 제시
    glColorPointer(3, GL_FLOAT, 0, MyColors);
    glVertexPointer(3, GL_FLOAT, 0, MyVertices);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(30.0, 1.0, 1.0, 1.0);
    for(GLint i=0; i<6; i++) {
        //최종적으로 6면체 그림
        glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, &MyVertexList[4*i]);
    }
    
    glFlush();
    

//    glColor3f(1.0f, 0.85f, 0.35f); //색지정
//    glViewport(0, 0, 512, 512);
//    glBegin(GL_POLYGON);//인자 들에 따른 차이
//    {
////        glVertex3f(0, 0.5, 0); //점지정
////        glVertex3f(-0.5, -0.5, 0); //점지정
////        glVertex3f(0.5, -0.5, 0); //점지정
//        glColor3fv(MyColors[0]); glVertex3fv(MyVertices[0]);
//        glColor3fv(MyColors[3]); glVertex3fv(MyVertices[3]);
//        glColor3fv(MyColors[2]); glVertex3fv(MyVertices[2]);
//        glColor3fv(MyColors[1]); glVertex3fv(MyVertices[1]);
//    
//    }
//
//    glEnd();
//    
//    glFlush();
////    glClear(GL_COLOR_BUFFER_BIT);
////    glBegin(GL_TRIANGLES);
////    glVertex2f(0, 0.1);
////    glVertex2f(-0.1, -0.1);
////    glVertex2f(0.1, -0.1);
//    glEnd();
//    glFlush();
}

void CreateGlutCallbacks() {
    glutDisplayFunc(display);
//    glutMouseFunc(<#void (*func)(int, int, int, int)#>)
//    glutKeyboardFunc(<#void (*func)(unsigned char, int, int)#>)
//    glutReshapeFunc(<#void (*func)(int, int)#>)
//    glutIdleFunc(<#void (*func)()#>)

}

void ExitGlut() {
    glutDestroyWindow(win);
    exit(0);
}

int main (int argc, char **argv) {
    // insert code here...
//    std::printf("dd", MyColors[0]);
    glutInit(&argc, argv);
    CreateGlutWindow();
    CreateGlutCallbacks();
    InitOpenGL();
    glutMainLoop();
    ExitGlut();
    return 0;
}



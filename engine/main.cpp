////
//// Created by Ethan Nerney on 11/1/18.
////
//
//#include <iostream>
//#include <math.h>
//#include <vector>
//#include <memory>
//#include "display.h"
//#include "Quadrangle.h"
//#include "MyQuad.h"
//#include "StarBoi.h"
//#include "Hyperspace.h"
//#include "ParticleSystem.h"
//#include "Fire.h"
//#include "PhysicsCircle.h"
//
//
//GLdouble width, height;
//int wd;
//using namespace position2D;
//using namespace colorGraphics;
//using namespace std;
//
//vector<Entity*> allEntities;
////MyQuad quad;
////StarBoi s(5, 5, 1, Vector2D(250, 250));
////StarSystem s(50, 10, 1000, 500, Vector2D(250,250));
//ParticleSystem s(100, 1, 100, 180, 15, 1, RGBColor(0.,0.,1.), Vector2D(250,250));
//ParticleSystem s2(500, 1, 20, 360, 40, 3, RGBColor(250,50,50), Vector2D(350,250));
//ParticleSystem s3(500, 1, 20, 360, 10, 3, RGBColor(250,250,50), Vector2D(250,250));
//
//
//Fire fire(50, GRAY, RED, RGBColor(255,165,0), RGBColor(255,255,0), Vector2D(250,250));
//
//PhysicsCircle circle;
//Circle c2(25, Vector2D(450,250),colorGraphics::GREEN);
//PhysicsAspect p2(&c2, 1, Circle(25,Vector2D(450,250),colorGraphics::GREEN));
//HyperSpace space(500, 10, 1000, 500, Vector2D(500, 250));
//
//
//void init() {
//    width = 1000;
//    height = 500;
//
//    //allEntities.push_back(&quad);
//    //createBoi();
//
//    //allEntities.push_back(&s);
//    //cout << PhysicsAspect::worldPhysicsAspects.size() << endl;
////    allEntities.push_back(&circle);
////    allEntities.push_back(&c2);
////    allEntities.push_back(&p2);
////    allEntities.push_back(&s);
////    allEntities.push_back(&s2);
//    //allEntities.push_back(&fire);
//
//    allEntities.push_back(&space);
//    //cout << PhysicsAspect::worldPhysicsAspects.size() << endl;
//
//}
//
///* Initialize OpenGL Graphics */
//void initGL() {
//    // Set "clearing" or background color
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
//}
//
///* Handler for window-repaint event. Call back when the window first appears and
// whenever the window needs to be re-painted. */
//void display() {
//    // tell OpenGL to use the whole window for drawing
//    glViewport(0, 0, width, height);
//
//    // do an orthographic parallel projection with the coordinate
//    // system set to first quadrant, limited by screen/window size
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
//
//    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
//
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//
//    /*
//     * Draw here
//     */
//
//    for (Entity* &e: allEntities) {
//        e->draw();
//    }
//
//
//
//
//    // Render now
//    glFlush();
//}
//
//// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
//void kbd(unsigned char key, int x, int y)
//{
//    // escape
//    if (key == 27) {
//        glutDestroyWindow(wd);
//        destroyAll();
//        exit(0);
//    } else if (key == 32) {
//        cout << "BLUE" << circle.p.collider.getCenter() << endl;
//        cout << "GREEN" << p2.collider.getCenter() << endl;
//
//
//    }
//
//
//    glutPostRedisplay();
//}
//
//void kbdS(int key, int x, int y) {
//    switch(key) {
//        case GLUT_KEY_DOWN:
//            circle.p.addForce(DOWN);
//            break;
//        case GLUT_KEY_LEFT:
//            circle.p.addForce(LEFT);
//            break;
//        case GLUT_KEY_RIGHT:
//            circle.p.addForce(RIGHT);
//            break;
//        case GLUT_KEY_UP:
//            circle.p.addForce(UP);
//            break;
//    }
//
//    glutPostRedisplay();
//}
//
//void cursor(int x, int y) {
//
//    glutPostRedisplay();
//}
//
//// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
//// state will be GLUT_UP or GLUT_DOWN
//void mouse(int button, int state, int x, int y) {
//
//    glutPostRedisplay();
//}
//
//void timer(int dummy) {
//    glutPostRedisplay();
//    glutTimerFunc(30, timer, dummy);
//
//    for (Entity* &e: allEntities) {
//        e->update();
//    }
////    s.update();
////    s2.update();
////    s3.update();
//
//}
//
///* Main function: GLUT runs as a console application starting at main()  */
//int main(int argc, char** argv) {
//
//    init();
//
//    glutInit(&argc, argv);          // Initialize GLUT
//
//    glutInitDisplayMode(GLUT_RGBA);
//
//    glutInitWindowSize((int)width, (int)height);
//    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
//    /* create the window and store the handle to it */
//    wd = glutCreateWindow("Fun with Drawing!" /* title */ );
//
//    // Register callback handler for window re-paint event
//    glutDisplayFunc(display);
//
//    // Our own OpenGL initialization
//    initGL();
//
//    // register keyboard press event processing function
//    // works for numbers, letters, spacebar, etc.
//    glutKeyboardFunc(kbd);
//
//    // register special event: function keys, arrows, etc.
//    glutSpecialFunc(kbdS);
//
//    // handles mouse movement
//    glutPassiveMotionFunc(cursor);
//
//    // handles mouse click
//    glutMouseFunc(mouse);
//
//    // handles timer
//    glutTimerFunc(0, timer, 0);
//
//    // Enter the event-processing loop
//    glutMainLoop();
//    return 0;
//}
//
//void createBoi() {}
//
//void destroyAll() {}

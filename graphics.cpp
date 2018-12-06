#include "graphics.h"
#include "engine/button.h"
#include "engine/particle_system.h"
#include "engine/structs.h"
#include "ink.h"
#include "hank.h"
#include "periwinkle.h"
#include <string.h>
using namespace colorGraphics;


/* WINDOW STUFF */
enum screen { START, MAIN, END, INSTRUCTION};
GLdouble width, height;
int wd;
screen currentScreen = START;
int scoreCounter;

/* BUTTONS */
Button startButton(Quad({0.17,0.88,0.55}, {480, 340}, 300, 75), "PLAY");
Button instructionsButton(Quad({0.76,.37,0.82}, {480, 420}, 300, 75), "INSTRUCTIONS");
Button quitButton(Quad({1,0.32,0.32}, {480, 500}, 300, 75), "QUIT");
Button backButton(Quad({0,0,1}, {65, 50}, 80, 50), "< BACK");


/* ITEMS */
Hank hank(position2D::Vector2D{480, 660,0});
Hank papaHank(position2D::Vector2D{150, 150,0}); // This is start screen hank
Periwinkle papaWink(25, position2D::Vector2D{810, 150,0}, {.36,0.5,.26}); // This is start screen wink
vector<Periwinkle> periwinkles;
vector<Ink> inks;

/* PARTICLE SYSTEMS */
vector<ParticleSystem> particleSystems {
    ParticleSystem(20, 4, 400, 2, 10, 10, RGBGradient(RGBColor(0.3,0.75,0.9), RGBColor(0., .9, 1.0)), position2D::Vector2D(100, 720, 271)),
    ParticleSystem(20, 3, 400, 2, 10, 10, RGBGradient(RGBColor(0.3,0.75,0.9), RGBColor(0., .9, 1.0)), position2D::Vector2D(270, 720, 271)),
    ParticleSystem(20, 5, 400, 2, 10, 10, RGBGradient(RGBColor(0.3,0.75,0.9), RGBColor(0., .9, 1.0)), position2D::Vector2D(680, 720, 271))
};


/* STATIC ITEMS */
vector<double> xPlacements; // The periwinkle placements


/* GLOBAL VARIABLES */
bool inPlay = false;

void init() {
    width = 960;
    height = 720;

    // This sets the placements of the periwinkles
    int spacing = 50;
    for (double i = spacing; i < width; i+=width/9) { xPlacements.push_back(i); }


}
/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.6f,0.7f,0.8f,1.0f);
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    switch(currentScreen) {    // Switch controls which screen draw method is displayed
        case START:
            displayScreenStart();
            break;

        case MAIN:
            displayScreenMain();
            break;
        case INSTRUCTION:
            displayScreenInst();
            break;

        case END:
            displayScreenEnd();
            break;

        default:break;
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y) {


    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    if (key == 32) {
        inks.emplace_back(hank.position);
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:
            hank.moveLeft(15);

            break;
        case GLUT_KEY_RIGHT:
            hank.moveRight(15);

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();
}

void cursor(int x, int y) {

    switch(currentScreen) {
        case START:

            // Mousing over startButton
            if (startButton.isOverlapping(x, y)) { startButton.hover(); }
            else { startButton.release(); }

            // Mousing over quitButton
            if (quitButton.isOverlapping(x, y)) { quitButton.hover(); }
            else { quitButton.release(); }

            // Mousing over inst button
            if (instructionsButton.isOverlapping(x, y)) { instructionsButton.hover(); }
            else { instructionsButton.release(); }


            break;

        case MAIN:

            if(x < width && x > 0) { hank.setPosition(position2D::Vector2D{(double)x, 660,0}); } // Move hank left and right with mouse movement

            break;

        case INSTRUCTION:

            // Mousing over backButton
            if (backButton.isOverlapping(x, y)) { backButton.hover();
            } else { backButton.release(); }

            break;

        case END:

            // Mousing over backButton
            if (backButton.isOverlapping(x, y)) { backButton.hover();
            } else { backButton.release(); }


            break;

        default:break;
    }


    //glutPostRedisplay(); //This speeds up the game with movement of the mouse
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    switch(currentScreen) {
        case START:

            // Start button handler
            if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && startButton.isOverlapping(x, y)) { startButton.pressDown();
            } else { startButton.release(); }

            // Sends user to main screen which begins a game
            if (state == GLUT_UP && button == GLUT_LEFT_BUTTON && startButton.isOverlapping(x, y)) { startButton.click(moveToMain); }



            // Quit button handler
            if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && quitButton.isOverlapping(x, y)) { quitButton.pressDown();
            } else { quitButton.release(); }

            // Calls the game quit handler
            if (state == GLUT_UP && button == GLUT_LEFT_BUTTON && quitButton.isOverlapping(x, y)) { quitButton.click(quitGame); }



            // Quit button handler
            if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && instructionsButton.isOverlapping(x, y)) { instructionsButton.pressDown();
            } else { instructionsButton.release(); }

            // Calls the game quit handler
            if (state == GLUT_UP && button == GLUT_LEFT_BUTTON && instructionsButton.isOverlapping(x, y)) { instructionsButton.click(moveToInst); }

            break;

        case MAIN:

            break;

        case INSTRUCTION:
            // Back button handler
            if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && backButton.isOverlapping(x, y)) { backButton.pressDown(); }
            else { backButton.release(); }

            // Move to the Start screen
            if (state == GLUT_UP && button == GLUT_LEFT_BUTTON && backButton.isOverlapping(x, y)) { backButton.click(moveToStart); }

            break;

        case END:

            // Back button handler
            if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON && backButton.isOverlapping(x, y)) { backButton.pressDown(); }
            else { backButton.release(); }

            // Move to the Start screen
            if (state == GLUT_UP && button == GLUT_LEFT_BUTTON && backButton.isOverlapping(x, y)) { backButton.click(moveToStart); }

            break;

        default:break;
    }

    glutPostRedisplay();
}

void timer(int dummy) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);

    for (auto &psys : particleSystems)
        psys.update();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int) width, (int) height);
    glutInitWindowPosition(100, 200); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Attack of the Periwinkles");

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    //glutKeyboardFunc(kbd);

    glutKeyboardUpFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}


/* Screen Handler's  */
void displayScreenStart(){


    string scoreText = "Attack of the Periwinkles";
    glColor3f(0,0,0);
    glRasterPos2f(width/2-120,100);
    for (char i : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }



    startButton.draw();
    instructionsButton.draw();
    quitButton.draw();
    papaHank.draw();
    papaWink.draw();

}

void displayScreenEnd(){

    string endGameText = "The evil Periwinkles invaded your home!";
    glColor3f(1,1,0);
    glRasterPos2f(width/2-150, 200);
    for (char i : endGameText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }

    string scoreText = "You fended off " + to_string(scoreCounter) + ((scoreCounter==1)? " wink!":" winks!");
    glColor3f(1,1,0);
    glRasterPos2f(width/2-100, 250);
    for (char i : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }

    for (auto &psys : particleSystems)
        psys.stop();

    backButton.draw();
}

void displayScreenMain(){

    for (auto &psys : particleSystems)
        psys.draw();

    displayText(width-125,20,0,0,0, "Score: " + to_string(scoreCounter));

    for (auto &periwinkle : periwinkles) {
        periwinkle.draw();
        if(periwinkle.getCenter().y >= 610) { // Handles game end (if a periwinkle gets to the bottom)
            moveToEnd();
        }
    }




    for(int i = 0; i<inks.size() ; i++){

        inks[i].draw();
        inks[i].translate(position2D::Vector2D{0.0,-5.0}); // Move the ink

        if(inks[i].getCenter().y <= 0) { // Checks to see if the ink is on on the top of screen
            inks.erase(inks.begin() + i);
        }

        for (int j = 0; j < periwinkles.size(); ++j) { // Checks to see if ink makes contact with any periwinkle
            if(inks[i].isOverlapping(periwinkles[j])) {
                inks.erase(inks.begin() + i);
                periwinkles.erase(periwinkles.begin() + j);
                ++scoreCounter;
                break;
            }
        }

    }

    hank.draw();

}

void displayScreenInst() {

    backButton.draw();

    string scoreText = "INSTRUCTIONS";
    glColor3f(1,0,1);
    glRasterPos2f(width/2-120,100);
    for (char i : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, i);
    }


    displayText(200,225,0,0,0,"A new invasive species, the Periwinkles of Peril");
    displayText(200,250,0,0,0,"are trying to take over the rocky shore that Hank lives in.");

    displayText(200,300,0,0,0,"Dont let the Periwinkles of peril touch the bottom and invade Hanks home!");
    displayText(200,325,0,0,0,"The Periwinkles will slowly get faster so watch out!");

    displayText(200,375,0,0,0,"Press [space] to shoot ink.");
    displayText(200,400,0,0,0,"Press [left arrow], [right arrow], or move the Mouse to move Hank.");

    displayText(200,450,0,0,0,"Help Hank defend his territory by throwing ink at them.");


}

/**
 * Change to the Start screen and reset animation variables
*/
void moveToStart() {
    glClearColor(0.6f,0.7f,0.8f,1.0f);
    currentScreen = START;
}

/**
 * Change screen to Main
 * Changes the clear color to game background
 * Resets the turn to X and resets the pieces
*/
void moveToMain() {
    glClearColor(0.4f,0.7f,0.8f,1.0f);
    resetGame();

    currentScreen = MAIN;

    for (auto &psys : particleSystems)
        psys.start();

    inPlay = true;
    addRow(3);
    glutTimerFunc(500, moveDown, 50*14);
    glutTimerFunc(7000, spawnRow, 50);

    glutSetCursor(GLUT_CURSOR_NONE);

}

/**
 * Change screen to End
*/
void moveToEnd() {
    glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
    glClearColor(0.6f,0.7f,0.8f,1.0f);
    currentScreen = END;
    inPlay = false;
}

/**
 * Change screen to Instructions
*/
void moveToInst(){
    currentScreen = INSTRUCTION;
}


/* HELPER FUNCTIONS */

/**
 * This function helps creating colored text
 * @param x the x position
 * @param y the y position
 * @param r the red value
 * @param g the green value
 * @param b the blue value
 * @param string te string to display
 *
 */
void displayText( float x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, string message) {
    glColor3f(r,g,b);
    glRasterPos2f(x,y);
    for (int i = 0; i < message.length(); i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, message[i] );
    }
}

/**
 * Calls closeGame, which terminates the window
 */
void quitGame() {
    glutDestroyWindow(wd);
    exit(0);
}

/**
 * Adds a row of periwinkles
 * @param number the number of winkles to add to the row
 */
void addRow(int number){

    double size = 25.0;
    int spacing = 50;
    double startY = size+5;
    colorGraphics::RGBColor color{.36,0.5,.26};


    vector<bool> placements = {false,false,false,false,false,false,false,false,false}; // 9 places to place the winkles


    // Randomly switch the placements to true
    int done = 0;
    while(done != number){
        int place = rand() % 9;
        if(!placements[place]){
            placements[place] = true;
            ++done;
        }
    }

    // Draw the winkles
    for (int i = 0; i < placements.size(); ++i) {
        if(placements[i]) { periwinkles.emplace_back(size,position2D::Vector2D{xPlacements[i], startY,0},color); }
    }





}

void spawnRow(int time) {
    unsigned int waitTime;
    if (time > 35) {
        waitTime = 7000;
        --time;
    } else if (time > 25) {
        waitTime = 5000;
        --time;
    } else if (time > 15) {
        waitTime = 3000;
        --time;
    } else {
        waitTime = 1500;
    }

    addRow(3);

    if (inPlay)
        glutTimerFunc(waitTime, spawnRow, time);
}

void moveDown(int time){
    double translateDist;
    if (time > 35*3) {
        translateDist = 20;
        --time;
    } else if (time > 25*3) {
        translateDist = 30;
        --time;
    } else if (time > 15*3) {
        translateDist = 35;
        --time;
    } else {
        translateDist = 45;
    }
    for (auto &periwinkle : periwinkles) {
        periwinkle.translate(position2D::Vector2D{0,translateDist});
    }

    if (inPlay)
        glutTimerFunc(500, moveDown, time);
}

/**
 *  Resets all the peices
 */
void resetGame() {
    periwinkles.clear();
    scoreCounter = 0;
    inks.clear();
    hank.setPosition(position2D::Vector2D{480, 660,0});
    inPlay = false;

}


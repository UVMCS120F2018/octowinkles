#include "graphics.h"
#include "engine/button.h"
#include "ink.h"
#include "hank.h"
#include "periwinkle.h"
#include <string.h>


/* WINDOW STUFF */
enum screen { START, MAIN, END, };
GLdouble width, height;
int wd;
screen currentScreen = START;
int scoreCounter;

/* BUTTONS */
Button startButton(Quad({0.17,0.88,0.55}, {480, 340}, 300, 75), "PLAY");
Button quitButton(Quad({1,0.32,0.32}, {480, 420}, 300, 75), "QUIT");
Button backButton(Quad({0,0,1}, {65, 50}, 80, 50), "< BACK");


/* ITEMS */
Hank hank(position2D::Vector2D{480, 660,0});
Hank papaHank(position2D::Vector2D{200, 200,0}); // This is start screen hank
vector<Periwinkle> periwinkles;
vector<Ink> inks;




void init() {
    width = 960;
    height = 720;



}
/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(255.0f, 255.0f, 255.0f, 1.0f); // Black and opaque
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

        case END:
            displayScreenEnd();
            break;

        default:break;
    }

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
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
            hank.moveLeft(10);

            break;
        case GLUT_KEY_RIGHT:
            hank.moveRight(10);

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

            break;

        case MAIN:
            break;

        case END:
            // Mousing over backButton
            if (backButton.isOverlapping(x, y)) { backButton.hover();
            } else { backButton.release(); }


            break;

        default:break;
    }
    glutPostRedisplay();
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

            break;

        case MAIN:

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
    glutKeyboardFunc(kbd);

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

    displayText(width/2-100,100,1,0,1, "Attack of the Periwinkles");
    startButton.draw();
    quitButton.draw();
    papaHank.draw();

}

void displayScreenEnd(){
    displayText(width/2,100,1,0,1, "You got to the end ");
    backButton.draw();
}

void displayScreenMain(){

    displayText(width-200,20,0,0,0, "Score: ");
    displayText(width-125,20,0,0,0, to_string(scoreCounter));

    for (auto &periwinkle : periwinkles) {
        periwinkle.draw();
        if(periwinkle.getCenter().y >= 610) { // Handles game end (if a periwinkle gets to the bottom)
            moveToEnd();
        }
    }


    hank.draw();

    for(int i = 0; i<inks.size() ; i++){
        inks[i].draw();
        inks[i].translate(position2D::Vector2D{0.0,-5.0});
        if(inks[i].getCenter().y == 0) {
            //TODO: Not removing for some reason!!!!!!!!!!!!!!!
            inks.erase(inks.begin() + i);
        }
    }
}

/**
 * Change to the Start screen and reset animation variables
*/
void moveToStart() {
    glClearColor(1.0f,1.0f,1.0f,1.0f); // white and opaque
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
    addRow();

    currentScreen = MAIN;

    addRow();
    glutTimerFunc(500, moveDown, 50*14);
    glutTimerFunc(7000, spawnRow, 50);
}

/**
 * Change screen to End
*/
void moveToEnd() {
    currentScreen = END;
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
 */
void addRow(){

    double size = 18.0;
    int spacing = 96;
    double startY = size+5;
    colorGraphics::RGBColor color{1.0,0.0,0.0};

    for (int i = 20; i <width ; i+=spacing) {
        periwinkles.emplace_back(size,position2D::Vector2D{i+20.,startY,0},color);
    }


}

void spawnRow(int time) {
    int waitTime;
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

    addRow();

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

    glutTimerFunc(500, moveDown, time);
}

/**
 *  Resets all the peices
 */
void resetGame() {
    periwinkles.clear();
    scoreCounter = 0;
}


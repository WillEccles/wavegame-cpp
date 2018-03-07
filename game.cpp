#include <iostream>
#include "wavegame.h"
#include <vector>
#include "gameObject.h"
#include "player.h"

#if ((defined _WIN32) || (defined _WIN64)) && !(defined __CYGWIN__)
#ifdef DEBUG
#pragma message "DEBUG: Load lib for WIN."
#endif
// windows without CYGWIN
#include <GL/glut.h>
#elif defined __CYGWIN__
#ifdef DEBUG
#pragma message "DEBUG: Load lib for cygwin."
#endif
// TODO: figure this one out
#elif defined __linux__
#ifdef DEBUG
#pragma message "DEBUG: Load lib for linux."
#endif
#include <GL/glut.h>
#elif (defined __APPLE__) && (defined __MACH__)
#ifdef DEBUG
#pragma message "DEBUG: Load lib for OS X."
#endif
#include <GLUT/glut.h>
#endif

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // clear color buffer

	for (auto& obj : game_objects) {
		obj->draw();
	}

	glFlush(); // render now
}

void keyDown(unsigned char key, int x, int y) {
	keys[key] = true;
}

void keyUp(unsigned char key, int x, int y) {
	keys[key] = false;
}

// should be called every frame as far as i know
void tick(int value) {
	addGameObject(new wavegame::trail(_player->getX(), _player->getY(), 20.0f, 20.0f, _player->getColor()));
	for (auto it = game_objects.begin(); it != game_objects.end(); ) {
		if ((*it)->garbage()) {
			delete (*it);
			it = game_objects.erase(it);
		} else {
			(*it)->tick();
			it++;
		}
	}
	glutPostRedisplay();
	glutTimerFunc(17, tick, 0);
}

void reshape(GLsizei width, GLsizei height) {
	glutReshapeWindow(1280, 720); // don't let them change the window size
}

void init() {
	glutCreateWindow("Wavegame");
	glutInitWindowSize(1280, 720);
	// make it so that 0.0,0.0 is bottom right
	// this is also making it so that the coordinates are out of 1280x720
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glLoadIdentity();
	gluOrtho2D(0.0, 1280.0, 0.0, 720.0);
	glViewport(0, 0, 1280, 720);
	glutInitWindowPosition((SCREENWIDTH-1280)/2, (SCREENHEIGHT-720)/2);
	// set handlers for things
	glutDisplayFunc(display);
	// set up the map of keys
	keys['w'] = false;
	keys['a'] = false;
	keys['s'] = false;
	keys['d'] = false;
	glutKeyboardFunc(keyDown);
	glutKeyboardUpFunc(keyUp);
	glutTimerFunc(0, tick, 0);
	glutReshapeFunc(reshape);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // background color
	_player = new player(color(255.0f, 0.0f, 0.0f));
	addGameObject(_player);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	init();
	glutMainLoop();
	return 0;
}

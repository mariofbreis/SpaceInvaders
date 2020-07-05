#ifndef SPACEINVADERS_H
#define SPACEINVADERS_H

#include <iostream>
#include <sstream>
#include <list>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <fstream>
#include <string>
#include <vector>

#define PI 3.14159265

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

#define TEMPO 1000/100

#define POSICAO_MAXIMA 10

#define TAMANHO_SHIP 0.9

#define TAMANHO_BASE 1.5

#define TAMANHO_ALIEN 0.3

#define MAX_SP_POSITION 9.5

#define MAX_DRAW_POSITION 10

#define MAX_WINDOW 12.0

#define MAX_GAME_POSITION 9.13

#define SHIP_SPEED 0.005

#define SHOT_SPEED 0.005

#define TAMANHO_BALA 0.03

#define DIM 150.0

#define CENTER DIM/2

#define PLAYER_SIZE 1

#define ALIEN_SIZE 0.4

#define BASE_SIZE 0.8

#endif
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SNAKE_MAX_LENGTH 100
#define FOOD_CHAR '@'
#define BORDER_CHAR '*'
#define EMPTY_CHAR ' ' 
#define SNAKE_BODY 'O'

typedef struct {
    int x, y;
} SnakeSegment;

typedef struct {
    char name[30];
    int score;
} RankingEntry;

RankingEntry ranking[3];

SnakeSegment* snake;
int snakeLength = 1;
int snakeDirection = 1;

int score = -10;

int foodX, foodY;
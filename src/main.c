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
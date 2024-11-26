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

void loadRanking() {
    FILE *file = fopen("ranking.dat", "rb");
    if (file != NULL) {
        fread(ranking, sizeof(RankingEntry), 3, file);
        fclose(file);
    }
}

void saveRanking() {
    FILE *file = fopen("ranking.dat", "wb");
    if (file != NULL) {
        fwrite(ranking, sizeof(RankingEntry), 3, file);
        fclose(file);
    }
}

void addPlayerToRanking(const char *name, int score) {
    for (int i = 0; i < 3; ++i) {
        if (score > ranking[i].score) {
            for (int j = 2; j > i; --j) {
                strcpy(ranking[j].name, ranking[j - 1].name);
                ranking[j].score = ranking[j - 1].score;
            }
            strcpy(ranking[i].name, name);
            ranking[i].score = score;
            break;
        }
    }
}

void showRanking() {
    printf("\n ----- RANKING -----\n");
    for(int i = 0; i<3; ++i) {
        printf("%d. %s - %d\n", i + 1, ranking[i].name, ranking[i].score);
    }
    printf("\n");
}

//funcao de atualizar o score de acordo com a quantidade de comida (10 em 10)
void updateScore() {
    screenGotoxy(MINX, MAXY);
    printf("Pontuação: %d\n", score);
}

void initializeGame() {
    screenInit(0);
    keyboardInit();
    timerInit(60);
    score = -10;
}

void endGame() {
    keyboardDestroy();
    screenDestroy();
    timerDestroy();
}

void initializeSnake() {
    snake = (SnakeSegment*)malloc(SNAKE_MAX_LENGTH * sizeof(SnakeSegment));
    snake[0].x = MAXX / 2;
    snake[0].y = MAXY / 2;
}

void freeSnake() {
    free(snake);
}

// geracao da comida de forma aleatoria no mapa
void generateFood() {
	
	foodX = rand() % (MAXX - MINX -1) + MINX + 1;
	foodY = rand() % (MAXY - MINY -1) + MINY + 1;
    score += 10;
}

// desenho da comida :/
void drawFood() {
	screenGotoxy(foodX, foodY);
	printf("%c", FOOD_CHAR);
}

void clearSnakeTail() {
	for (int i = snakeLength; i < SNAKE_MAX_LENGTH; i++) {
		snake[i].x = 0;
		snake[i].y = 0;
	}
}

void drawSnake() {
	for(int i = 0; i < snakeLength; i++) {
        screenGotoxy(snake[i].x, snake[i].y);
        printf("%c", SNAKE_BODY);
	}
}

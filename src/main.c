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
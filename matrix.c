//Copyright © 2016 Brian Pomerantz. All Rights Reserved.

#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[]) {
    FILE *fp;
    char tempcols[3], templines[3];

    fp = popen("tput cols", "r");
    if (fp == NULL) {
        printf("Failed to obtain size of terminal.\n");
        exit(1);
    }

    fgets(tempcols, sizeof(tempcols), fp);

    fp = popen("tput lines", "r");
    if (fp == NULL) {
        printf("Failed to obtain size of terminal.\n");
        exit(1);
    }

    fgets(templines, sizeof(templines), fp);

    int cols = atoi(tempcols);
    int lines = atoi(templines);

    pclose(fp);
    
    
    curs_set(0);
    initscr();

    int i, j;
    for (i = 0; i < lines; i++) {
        for (j = 0; j < cols; j++) {
            move(i, j);
            printw("%d", i);
        }
        
        refresh();
        usleep(100000);
    }

    endwin();

    return 0;
}

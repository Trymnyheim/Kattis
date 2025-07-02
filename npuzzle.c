// https://open.kattis.com/problems/npuzzle

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *board = malloc(17);
    char *line = malloc(10);
    if (board == NULL) {
        fprintf(stderr, "Failed to allocate memory.\n");
        return -1;
    }

    int i = 0;
    while (i < 16) {
        if (fgets(line, 10, stdin) == NULL) {
            fprintf(stderr, "Failed to read input.\n");
            free(board);
            free(line);
            return -1;
        }
        strncpy(board + i, line, 4);
        i += 4;
    }
    free(line);
    board[16] = '\0';

    int currentRow, currentCol, idealI,idealRow, idealCol, diff;
    int totalDiff = 0;
    for (int i = 0; i < 16; i++) {
    
        if (board[i] == '.')
            continue;

        // From 1D-array index to cols and rows:
        currentRow = i / 4;
        currentCol = i % 4;

        idealI = board[i] - 65; // Position in alphabet

        idealRow = idealI / 4;
        idealCol = idealI % 4;

        diff = abs(currentRow - idealRow) + abs(currentCol - idealCol);
        totalDiff += diff;
    }

    // Give result:
    printf("%d\n", totalDiff);

    free(board);
    return 0;
}
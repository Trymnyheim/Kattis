// https://open.kattis.com/problems/eulerian

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    int N, M;
    char buffer[20];
    if (fgets(buffer, 20, stdin) == NULL) {
        fprintf(stderr, "Error reading first input-line.\n");
        return -1;
    }

    if (sscanf(buffer, "%d %d", &N, &M) != 2) {
        fprintf(stderr, "Error parsing first input-line\n");
        return -1;
    }

    int out[N + 1]; // Maps vertex's out-degree
    int in[N + 1]; // Maps vertex's in-degree

    // Init to 0:
    for (int i = 1; i < N + 1; i++) {
        out[i] = 0;
        in[i] = 0;
    }

    // Read edges and calculate in/out-degrees:
    int from, to;
    while (M > 0) {
        if (fgets(buffer, 20, stdin) == NULL) {
            fprintf(stderr, "Failed reading edge-input.\n");
            return -1;
        }

        if (sscanf(buffer, "%d %d", &from, &to) != 2) {
            fprintf(stderr, "Error parsing edge-input\n");
            return -1;
        }

        out[from]++;
        in[to]++;

        M--;
    }

    // Check in/out-grades of vertices:
    int odd = 0;
    bool hasPath = true;
    int largerOut = -1; // v with larger out than in
    int largerIn = -1;  // v with larger in than out
    for (int i = 1; i < N + 1; i++) {

        if (out[i] == in[i])
            continue; // Ignore even nodes

        if (out[i] == in[i] + 1) {
            if (largerOut != -1) {
                hasPath = false; // Can not exist two with larger out than in
                break;
            }
            largerOut = i;
        }
        else if (in[i] == out[i] + 1) {
            if (largerIn != -1) {
                hasPath = false; // Can not exist two with larger in than out
                break;
            }
            largerIn = i;
        }
        else {
            hasPath = false; // Diff in in and out > 1 is not allowed
            break;
        }
    }

    // Give appropriate output:
    if (!hasPath)
        printf("no\n");
    else if (largerIn != -1 && largerOut != -1)
        printf("%d %d\n", largerOut, largerIn);
    else if (hasPath)
        printf("anywhere\n");
    else
        printf("no\n");

    return 0;
}
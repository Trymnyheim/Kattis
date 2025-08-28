// https://open.kattis.com/problems/birthday

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODE 100
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int solve(int p, int c);
int has_sep_node(uint8_t neighbours[MAX_NODE][MAX_NODE], int N);
int separationnodes_rec(uint8_t neighbours[MAX_NODE][MAX_NODE], int u, int d, int *depth, int *low, int *parent, int N, int *visited);

int main() {
    char buffer[20];
    while (1) {
        int p, c;
        if (fgets(buffer, 20, stdin) == NULL) break;
        if (sscanf(buffer, "%d %d", &p, &c) != 2) break;
        if (p == 0 && c == 0) break;

        solve(p, c);
    }
    return 0;
}

int solve(int p, int c) {
    char buffer[20];
    int a, b;
    uint8_t neighbours[MAX_NODE][MAX_NODE] = {0};

    while (c-- > 0) {
        if (fgets(buffer, 20, stdin) == NULL) return -1;
        if (sscanf(buffer, "%d %d", &a, &b) != 2) return -1;
        neighbours[a][b] = 1;
        neighbours[b][a] = 1;
    }

    if (has_sep_node(neighbours, p))
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}

int has_sep_node(uint8_t neighbours[MAX_NODE][MAX_NODE], int N) {
    int depth[MAX_NODE] = {0};
    int low[MAX_NODE] = {0};
    int parent[MAX_NODE];
    int visited[MAX_NODE] = {0};

    for (int i = 0; i < N; i++) parent[i] = -1;

    if (separationnodes_rec(neighbours, 0, 1, depth, low, parent, N, visited)) {
        return 1;  // found articulation
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) return 1;  // not connected
    }

    return 0;  // connected and no articulation point
}

int separationnodes_rec(uint8_t neighbours[MAX_NODE][MAX_NODE], int u, int d, int *depth, int *low, int *parent, int N, int *visited) {
    depth[u] = low[u] = d;
    visited[u] = 1;
    int children = 0;

    for (int v = 0; v < N; v++) {
        if (!neighbours[u][v]) continue;

        if (!depth[v]) {
            parent[v] = u;
            children++;

            if (separationnodes_rec(neighbours, v, d + 1, depth, low, parent, N, visited))
                return 1;

            low[u] = MIN(low[u], low[v]);

            if ((parent[u] != -1 && low[v] >= depth[u]) || (parent[u] == -1 && children > 1))
                return 1;  // articulation point
        } else if (v != parent[u]) {
            low[u] = MIN(low[u], depth[v]);
        }
    }

    return 0;
}

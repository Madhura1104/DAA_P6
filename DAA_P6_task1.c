#define INF 9999
#include <stdio.h>

int n = 4;

void optimal_bst(float p[], float q[], int n, float e[][n + 1], int root[][n + 1]);

int main() {
    float p[] = {0, 0.1, 0.2, 0.4, 0.3};
    float q[] = {0.05, 0.1, 0.05, 0.05, 0.1};
    float e[n + 2][n + 1];
    int root[n + 1][n + 1];

    optimal_bst(p, q, n, e, root);

    printf("cost of an optimal BST is: %f\n", e[1][4]);

    return 0;
}

void optimal_bst(float p[], float q[], int n, float e[][n + 1], int root[][n + 1]) {
    float w[n + 2][n + 1];
    int j, r;

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            e[i][j] = INF;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (r = i; r <= j; r++) {
                float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}
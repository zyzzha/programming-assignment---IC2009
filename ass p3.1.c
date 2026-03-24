#include <stdio.h>

int main() {
    int m, n, i, j;
    scanf("%d %d %d %d", &m, &n, &i, &j);

    int dx[8] = {2,2,-2,-2,1,1,-1,-1};
    int dy[8] = {1,-1,1,-1,2,-2,2,-2};

    for(int k=0; k<8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];

        if(x >= 1 && x <= m && y >= 1 && y <= n) {
            printf("(%d,%d)\n", x, y);
        }
    }

    return 0;
}

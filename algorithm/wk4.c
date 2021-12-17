#include <stdio.h>

// Flood fill

int Q[100][3];
int head, tail;
int map[5][5];
int M, N;
int sx, sy;
int ex, ey;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int main()
{
    int x, y;
    int nx, ny, level;
    int i, j;

    scanf("%d %d", &M, &N);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &ex, &ey);

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            map[i][j] = -1;
        }
    }

    Q[0][0] = 2;
    Q[0][1] = 2;
    Q[0][2] = 1;
    map[2][2] = 1;
    tail++;
    while(head - tail)
    {
        nx = Q[head][0];
        ny = Q[head][1];
        level = Q[head][2];
        for(i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx == ex && ny == ey ) {
                printf("%d\n", level);
                return;
            }
            if ( nx < 0 || ny < 0 || nx >= 5 || ny >= 5 )
                continue;
            if ( map[nx][ny] > 0 )
                continue;
            if ( map[nx][ny] == -1 )
                continue;
            map[nx][ny] = level + 1;
            Q[tail][0] = nx;
            Q[tail][1] = ny;
            Q[tail++][2] = level + 1;

        }
        // When every work is done...
        head++;
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ",  &map[i][j]);
        }
    }

    return 0;
}
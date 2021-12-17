#include <stdio.h>
#include <stdbool.h>
#include <memory.h>

// We call this algorithm as sliding window
// Tip: modulo operator is fucking slow
// In ps, we're lack of time, but we've got sufficient storage
// So we can adopt a strategy of converting storage to time

int foods[10000001];
int foods_table[201];

int main()
{
    int T, R, N;

    scanf("%d", &T);
    bool result[T];
    memset(result, true, T * sizeof(bool));
    
    int i, j, k;
    for (i = 0; i < T; i++) {
        scanf("%d %d", &N, &R);
        for (j = 0; j < N; j++) {
            scanf("%d", &foods[j]);
        }
        for (j = 0; j < N; j++) {
            if (j == 0) {
                for (k = 0; k < R; k++) {
                    if (foods_table[foods[k]] == 2) {
                        j = N;
                        k = R;
                        result[i] = false;
                        break;
                    }
                    foods_table[foods[k]]++;
                }
            } else {
                if ( j - R > 0 ) {
                    foods_table[foods[j-R-1]]--;
                }
                if ( j + R < N ) {
                    if (foods_table[foods[j+R]] == 2) {
                        j = N;
                        result[i] = false;
                        break;
                    }
                    foods_table[foods[j+R]]++;
                }
            }
        }
        if (i != T - 1) {
            memset(foods_table, 0, 201 * sizeof(int));
        }
    }
    printf('\n');
    for (j = 0; j < T; j++) {
        printf("#%d %s\n", j+1, result[j] ? "YES" : "NO");
    }

    return 0;
}
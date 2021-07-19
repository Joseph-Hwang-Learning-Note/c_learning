#include <stdio.h>

int main()
{

    // declaration part
    int bresult = 0;

    int rheight;
    int rwidth;
    int bheight;
    int bwidth;

    int table[100001] = {0};

    // input receiving part
    scanf("%d %d", &rheight, &rwidth);
    int residents[rheight][rwidth];
    for (int i = 0; i < rheight; i++)
    {
        for (int j = 0; j < rwidth; j++)
        {
            scanf("%d", &residents[i][j]);
        }
    }

    scanf("%d %d", &bheight, &bwidth);
    int blacklist[bheight][bwidth];
    for (int i = 0; i < bheight; i++)
    {
        for (int j = 0; j < bwidth; j++)
        {
            scanf("%d", &blacklist[i][j]);
        }
    }

    // processing part
    for (int i = 0; i < rheight; i++)
    {
        for (int j = 0; j < rwidth; j++)
        {
            table[residents[i][j]]++;
        }
    }

    for (int i = 0; i < bheight; i++)
    {
        for (int j = 0; j < bwidth; j++)
        {
            bresult = bresult + table[blacklist[i][j]];
            table[blacklist[i][j]] = 0;
        }
    }

    // output part
    printf("%d\n", bresult);
    printf("%d\n", rheight * rwidth - bresult);

    return 0;
}
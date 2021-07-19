#include <stdio.h>

int data[100]; // 자동으로 0으로 초기화됨

void quick(int *data, int head, int tail)
{
    if (tail - head < 1)
    {
        return;
    }
    int pivot = head;
    int start = head + 1;
    int end = tail;
    int temp;

    while (start <= end)
    {
        while (start <= tail && data[start] <= data[pivot])
        {
            start++;
        }
        while (end > head && data[end] >= data[pivot])
        {
            end--;
        }
        if (start > end)
        {
            temp = data[end];
            data[end] = data[pivot];
            data[pivot] = temp;
        }
        else
        {
            temp = data[start];
            data[start] = data[end];
            data[end] = temp;
        }
    }
    quick(data, head, end - 1);
    quick(data, end + 1, tail);
}

int main()
{
    int i;
    int N;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }
    quick(data, 0, N - 1);
    for (i = 0; i < N; i++)
    {
        printf("%d", data[i]);
    }

    return 0;
}

// DAT: Direct Address Table
// 특수한 경우 빠르나, 메모리 엄청 많이 잡아먹는다

#include <stdio.h>
#define frame 10
#define framesize 10
int arr[frame][framesize];
int page[framesize];
int main()
{
    int i, j, k, n, b;
    int failure = 0, found;
    for (i = 0; i < frame; i++)
        for (j = 0; j < framesize; j++)
            arr[i][j] = -1;
    printf("\nEnter the no. of frame available: ");
    scanf("%d", &b);
    printf("\nEnter the no. of pageframe to be called: ");
    scanf("%d", &n);
    printf("\nEnter the no. of page frame array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);
    arr[0][0] = page[0];
    failure++;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < b; j++)
        {
            found = 0;
            if (arr[i][i - 1] == page[i])
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            for (k = b; k > 0; k--)
                arr[k][i] = arr[k - 1][i - 1];
            arr[k][i] = page[i];
            failure++;
        }
        else
        {
            arr[0][i] = page[i];
            for (k = 1; k < b; k++)
                if (k > j)
                    arr[k][i] = arr[k][i - 1];
                else
                    arr[k][i] = arr[k - 1][i - 1];
        }
    }
    printf("\n Page replacement using LRU\n");
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < n; j++)
            if (arr[i][j] != -1)
                printf("%2d ", arr[i][j]);
        printf("\n");
    }
    printf("\nNo. of replacement failed: %d out of %d", failure, n);
    printf("\nNo. of replacement success: %d out of %d", n - failure, n);
}
#include <stdio.h>
int b_allocated[30];
void display(int);
void main()
{
    int
        j = 0,
        index[50], indexloc, i, n, no, psize, pname, block, freespace = 0, count = 0;
    printf("\nEnter the number of blocks: ");
    scanf("%d", &n);
    freespace = n;
    printf("\nEnter the number of blocks that are already allocated: ");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
        b_allocated[i] = 0;
    printf("\nEnter the blocks allocated: ");
    for (i = 0; i < no; i++)
    {
        scanf("%d", &block);
        b_allocated[block] = 1;
        freespace = freespace - 1;
    }
    printf("\nFreespace=%d\n", freespace);
    display(n);
    printf("\nEnter the name of the process: ");
    scanf("%d", &pname);
    printf("\nEnter the size of the process: ");
    scanf("%d", &psize);
    if (psize < freespace)
    {
        for (i = 0; i < n; i++)
        {
            if (b_allocated[i] == 0 && count <= psize)
            {
                if (count == psize)
                {
                    b_allocated[i] = pname;
                    indexloc = i;
                    break;
                }
                else
                {
                    b_allocated[i] = 1;
                    index[j] = 0;
                    index[j] = i;
                    j = j + 1;
                    count = count + 1;
                }
            }
        }
        display(n);
        printf("\nBlocks stored in index are: \n\n");
        for (i = 0; i < j; i++)
            printf("%d", index[i]);
        printf("\nDirectory Structure\n\n");
        printf("\nProcess\t\tIndex\n");
        printf("\n%d\t\t%d", pname, indexloc);
    }
}
void display(int n)
{
    int i, count = 0;
    printf("\n\n");
    for (i = 0; i < n; i++)
        if (count < 3)
        {
            printf("\t\tb[%2d]-->%d", i, b_allocated[i]);
            count = count + 1;
        }
        else
        {
            printf("\n\n\t\tb[%2d]--%d", i, b_allocated[i]);
            count = 1;
        }
}
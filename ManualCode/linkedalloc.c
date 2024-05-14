#include <stdio.h>
void display();
struct block
{
    int p_id;
    int b_allocated;
    struct block *next;
} *sblock = NULL;
int n;
struct block b[50];
int main()
{
    int i, pname, psize, no, bname, freespace = 0, count, previous;
    printf("\nEnter the no. of blocks: ");
    scanf("%d", &n);
    freespace = n;
    for (i = 0; i < n; i++)
    {
        b[i].p_id = 0;
        b[i].b_allocated = 0;
    }
    printf("\nEnter the no. of blocks already allocated process name: ");
    scanf("%d", &no);
    for (i = 0; i < no; i++)
    {
        printf("\nEnter the block: ");
        scanf("%d", &bname);
        b[bname].p_id = 100;
        b[bname].b_allocated = 1;
        freespace = freespace - 1;
    }
    display();
    printf("\nEnter process name: ");
    scanf("%d", &pname);
    printf("\nEnter process size: ");
    scanf("%d", &psize);
    count = 0;
    if (psize <= freespace)
    {
        for (i = 0; i < n; i++)
        {
            if (b[i].b_allocated == 0)
            {
                b[i].b_allocated = 1;
                b[i].p_id = pname;
                count++;
                if (count == 1)
                    sblock = &b[i];
                else if (count > psize)
                    break;
                else
                    b[previous].next = &b[i];
                previous = i;
            }
        }
        display();
printf("\nProcess name %d\nStarting address %u\nEnding address%u",pname,sblock,&b[i]);
    }
    else
        printf("\nProcess cannot be allocated");
}
void display()
{
    int i, count = 0;
    printf("\nBlocks\n");
    for (i = 0; i < n; i++)
    {
        if (count < 2)
printf("%u-->\tb[%2d]->\t%2d->\t%2d->\t%4u\t\t",&b[i],i,b[i].p_id,b[i].b_allocated,b[i].next);
else
{
                count = 0;
printf("\n%u-->\tb[%2d]->\t%2d->\t%2d->\t%4u\t\t",&b[i],i,b[i].p_id,b[i].b_allocated,b[i].next);
}
count=count+1;
    }
}
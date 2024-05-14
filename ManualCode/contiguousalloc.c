#include<string.h>
#include<stdio.h>
struct block
{
int b_id;
int b_allocated;
};
struct block b[50];
int main()
{
int no,i,j,n,sblock,eblock,count=0;
int psize,flag=1,pname,bname;
printf("\nEnter the no. of block: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
b[i].b_id=i;
b[i].b_allocated=0;
}
printf("\nEnter the no. of block already exists: ");
scanf("%d",&no);
for(i=0;i<no;i++)
{
printf("\nEnter the block: ");
scanf("%d",&bname);
b[bname].b_allocated=100;
}
printf("\nEnter the process name: ");
scanf("%d",&pname);
printf("\nEnter the process size: ");
scanf("%d",&psize);
for(i=0;i<n;i++)
{
if(b[i].b_allocated==0)
{
count=count+1;
if(count==1)
sblock=i;
if(count==psize)
{
eblock=i;
for(j=sblock;j<=eblock;j++)
b[j].b_allocated=pname;
printf("\n\nProcess %d is allocated %d blocks from %d to%d\n\n",pname,sblock,eblock,sblock);
i=n+1;
flag=1;
}
}
else
{
count=0;
flag=0;
}
}
if(flag==0)
printf("\nProcess not allocated");
count=0;
for(i=0;i<n;i++)
{
count=count+1;
if(count<no)
printf("b[%d]->%d\t\t",b[i].b_id,b[i].b_allocated);
else
{
count=0;
printf("\n\n\nb[%d]-->%d\t\t",b[i].b_id,b[i].b_allocated);
count=count+1;
}
}
return 0;
}
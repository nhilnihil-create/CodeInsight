#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
int i,x,y,k=0;

int a=2;
int b[7]={1,3,5,7,8,10,12};
int c[4]={4,6,9,11};
scanf("%d %d",&x,&y);
for(i=0;i<4;i++)
{
   if(x==c[i])
    {
     for(i=0;i<4;i++)
     {
      if(y==c[i])
      {
       printf("Yes"); 
	   k=5;
      }
     }
    }
}
for(i=0;i<7;i++)
{
   if(x==b[i])
    {
     for(i=0;i<7;i++)
     {
      if(y==b[i])
      {
       printf("Yes"); 
	   k=5;
      }
    }
    }
}
if(k!=5)
printf("No");
}
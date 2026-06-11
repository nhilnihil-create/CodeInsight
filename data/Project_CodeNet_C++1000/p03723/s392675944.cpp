#include<bits/stdc++.h>
using namespace std;

int main()
{
int A,B,C,count=0,ba=0,bb=0,bc=0;scanf("%d %d %d",&A,&B,&C);
while(A%2!=1&&B%2!=1&&C%2!=1)
{
  if(max({ba,bb,bc})==max({A,B,C})&&min({ba,bb,bc})==min({A,B,C})){count=-1;break;}
  int a=A/2,b=B/2,c=C/2;ba=A,bb=B,bc=C;
  A=b+c,B=a+c,C=a+b;
  count++;
}
printf("%d\n",count);
}
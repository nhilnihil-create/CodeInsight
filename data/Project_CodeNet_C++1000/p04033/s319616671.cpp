#include<bits/stdc++.h>
using namespace std;

int main()
{
  int a,b;scanf("%d %d",&a,&b);
  if(a<=0&&b>=0){printf("Zero\n");return 0;}
  if(a>0){printf("Positive\n");return 0;}
  if((b-a)%2==1)printf("Positive\n");
  else printf("Negative\n");
}
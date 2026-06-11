#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int a[N];
  for(int i=0;i<N;i++)scanf("%d",&a[i]);
  bool col[8];fill(col,col+8,false);
  sort(a,a+N);int minans=0,maxans=0;
  for(int i=0;i<N;i++)
  {
    if(a[i]>=3200)
    {
      if(minans==0)minans++;
      maxans++;continue;
    }
    if(!col[a[i]/400]){minans++;maxans++;}
    col[a[i]/400]=true;
  }
  printf("%d %d",minans,maxans);
}
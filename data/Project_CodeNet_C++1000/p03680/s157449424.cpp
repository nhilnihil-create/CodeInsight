#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int a[N];bool A[N];fill(A,A+N,false);
  for(int i=0;i<N;i++){scanf("%d",&a[i]);a[i]--;}
  int i=0,ans=0;
  while(i!=1)
  {
    A[i]=true;
    i=a[i];ans++;
    if(A[i]){printf("-1");return 0;}
  }
  printf("%d",ans);
}
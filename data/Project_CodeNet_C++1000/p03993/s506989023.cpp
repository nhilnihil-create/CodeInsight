#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;scanf("%d",&N);
  int a[N],ans=0;
  for(int i=0;i<N;i++){scanf("%d ",&a[i]);a[i]--;}
  for(int i=0;i<N;i++)if(a[a[i]]==i)ans++;
  printf("%d\n",ans/2);
}
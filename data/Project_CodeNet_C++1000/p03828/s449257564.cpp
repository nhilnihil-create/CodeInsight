#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

void count_factor(int n,map<int,int>& m)
{
  for(int i=2;i<=n;i++)if(n%i==0){n/=i;m[i]++;i--;}
}

int main()
{
  int N;unsigned long long ans=1;scanf("%d",&N);map<int,int> m;
  for(int n=N;n>0;n--)count_factor(n,m);
  for(auto p : m){ans=ans*(p.second+1)%INF;}
  printf("%llu\n",ans);
}
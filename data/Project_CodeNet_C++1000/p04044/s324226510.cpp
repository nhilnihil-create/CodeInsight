#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N,L;scanf("%d %d",&N,&L);
  string S[N];
  for(int i=0;i<N;i++)cin>>S[i];
  sort(S,S+N);
  string ans;
  for(int i=0;i<N;i++)ans+=S[i];
  cout<<ans;
}
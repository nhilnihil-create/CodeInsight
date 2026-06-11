#include<bits/stdc++.h>
using namespace std;

int main()
{
int N;string S;
scanf("%d\n",&N);
cin>>S;int x=0;int ans=0;
for(int i=0;i<S.size();i++)
{
  if(S[i]=='I')x++;
  else x--;
  ans=max(ans,x);
}
printf("%d\n",ans);
}
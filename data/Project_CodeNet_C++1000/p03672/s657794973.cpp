#include<bits/stdc++.h>
using namespace std;

int main()
{
  string S;cin>>S;
  for(int i=1;i<S.size();i++)
  {
    bool check=true;
    if((S.size()-i)%2==1)continue;
    for(int j=0;j<(S.size()-i)/2;j++)if(S[j]!=S[j+(S.size()-i)/2])check=false;
    if(check){printf("%d",S.size()-i);return 0;}
  }
}
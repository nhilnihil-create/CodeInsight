#include<iostream>
using namespace std;

int main()
{
  string S;
  string ans="CODEFESTIVAL2016";
  cin>>S;
  int cnt=0;
  for(int i=0;i<S.size();i++){
    if(S[i]==ans[i]) continue;
    cnt++;
  }
  cout<<cnt;
}
  
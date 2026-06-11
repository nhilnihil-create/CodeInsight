#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  string s;cin>>s;

  if(s[0]==s[s.size()-1] ^ s.size()%2==1)cout<<"First";
  else cout<<"Second";

  return 0;
}
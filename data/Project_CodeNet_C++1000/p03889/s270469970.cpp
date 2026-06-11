#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  string S;
  cin>>S;
  map<char,char> A;
  A['q']='p',A['p']='q',A['b']='d',A['d']='b';
  string T=S;
  reverse(T.begin(),T.end());
  for(char &c:T)c=A[c];
  if(S==T)puts("Yes");
  else puts("No");
}
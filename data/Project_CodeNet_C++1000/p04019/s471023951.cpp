#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string S;
  cin >>S;
  bool s=false, n=false, w=false, e=false;
  rep(i,S.size()){
    if(S[i]=='S') s=true;
    if(S[i]=='N') n=true;
    if(S[i]=='W') w=true;
    if(S[i]=='E') e=true;
  }
  bool sn = false, we = false;
  if(s==n) sn=true;
  if(w==e) we=true;
  if(sn==true && we==true) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
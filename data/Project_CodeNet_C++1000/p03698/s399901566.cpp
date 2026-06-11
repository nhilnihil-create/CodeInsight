#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  string S; cin >>S;
  int check[26]={};
  rep(i,0,S.size()) {
    int temp=S[i]-'a';
    check[temp]++;
  }
  bool flag=true;
  rep(i,0,26) {
    if (1<check[i]) {flag=false; break;}
  }
  cout <<(flag ? "yes":"no") <<endl;
  return 0;    
}

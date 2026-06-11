#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main(){
  string ans="";
  rep(i,0,3) {
    string s; cin >>s;
    ans.push_back(s[0]);
  }
  transform(ans.begin(),ans.end(),ans.begin(),::toupper);
  cout <<ans <<endl;
  return 0;
}

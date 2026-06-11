#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define INF INT_MAX;
typedef long long ll;
using namespace std;

int main(){
  string t; cin >> t;
  bool n=false,e=false,s=false,w=false;
  rep(i,t.size()){
    char c = t.at(i);
    if(c=='N') n=true;
    if(c=='E') e=true;
    if(c=='S') s=true;
    if(c=='W') w=true;
  }
  if(n==s&&e==w) puts("Yes");
  else puts("No");
}
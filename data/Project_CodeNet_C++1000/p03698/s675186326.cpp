#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<string> vs;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  vs a(26);
  int n=(int)s.size();
  char c[n];
  int m=0;
  rep(i, n){
    bool t=true;
    rep(j, i)if(c[j]==s[i])t=false;
    if(t){
      c[m]=s[i];
      m++;
    }
  }
  bool ans=true;
  rep(i, n)if(c[i]!=s[i]){
    ans=false;
    break;
  }

  cout << (ans ? "yes" : "no") << endl;

  return 0;
}
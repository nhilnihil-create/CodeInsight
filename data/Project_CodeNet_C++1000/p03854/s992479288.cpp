#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  string S; cin >> S;
  reverse(all(S));
  vector<string> T = {"dream", "dreamer", "erase", "eraser"} ;
  rep(i,4) reverse(all(T[i]));
  int jd = 0;
  while (jd < 4){
    rep(i,4){
      if(S.substr(0,T[i].size()) == T[i]){
        S = S.substr(T[i].size());
        if (S.size() == 0 ) { cout << "YES" << endl; return 0;}
        jd = 0; break;
      }
      jd++;
    }
  }
  cout << "NO" << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr ll mod = 1e9+7;
int main(){ 
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  ll res = 0;
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      if (s1[i] == s2[i]) {
        res += 3;
        s = 0;
      } else {
        res += 6;
        s = 1;
      }
    } else {
      if (s1[i] == s2[i]) {
        if (s) {
          s = 0;
        } else {
          (res *= 2) %= mod;
          s = 0;
        }
      } else {
        if (s && s1[i] != s1[i-1]) {
          (res *= 3) %= mod;
          s = 1;
        } else if(s == 0){
          (res *= 2) %= mod;
          s = 1;
        }
      }
    }
  }
  cout << res << endl;
  return 0;
} 
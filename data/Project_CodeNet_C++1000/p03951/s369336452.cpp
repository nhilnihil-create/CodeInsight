#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  for(int i = 0; i < n; ++i){
    bool bfind = true;
    for(int j = 0; j < n - i; ++j){
      if(s[i+j] != t[j]){
        bfind = false;
        break;
      }
    }
    if(bfind){
      for(int j = n-i; j < n; ++j){
        s += t[j];
      }
      cout << s.size() << endl;
      return 0;
    }
  }
  cout << s.size() + t.size() << endl;
  return 0;
}

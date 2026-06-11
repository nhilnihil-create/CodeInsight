#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9 + 7;

int main(){ 
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  int mx = 0;
  rep(i, t) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  cout << max(mx - 1 - (k - mx), 0);
  return 0;
} 
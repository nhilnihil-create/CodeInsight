#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  vector<tuple<double,int,int>> ans;
  vector<int> watersum;
  for(int i = 0; i<=30; i++) {
    for(int j = 0; j<=30; j++) {
      if(i==0 && j==0) continue;
      int sum = 100*(a*i+b*j);
      if(sum<=f) watersum.push_back(sum);
    }
  }
  rep(i,watersum.size()) {
    int water = watersum[i];
    int sugarmax = min(water/100*e,f-water);
    bool dp[sugarmax+1];
    rep(j,sugarmax+1) dp[j] = false;
    dp[0] = true;
    for(int j = 1; j <= sugarmax; j++) {
      bool ok = false;
      if(j-c>=0) if(dp[j-c]) ok = true;
      if(j-d>=0) if(dp[j-d]) ok = true;
      if(ok) dp[j] = true;
    }
    int sugar;
    per(j,sugarmax+1) {
      if(dp[j]) {
        sugar = j;
        break;
      }
    }
    double con = sugar / (double)(water+sugar);
    tuple<double,int,int> p = make_tuple(con,(sugar+water),sugar);
    ans.push_back(p);
  }
  sort(ans.begin(),ans.end());
  reverse(ans.begin(),ans.end());
  int x, y;
  tie(ignore,x,y) = ans[0];
  cout << x << " " << y << endl;
  return 0;
}
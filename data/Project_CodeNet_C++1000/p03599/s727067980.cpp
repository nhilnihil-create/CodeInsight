#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

int main(){
  ll a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  db maxcon = 0;
  ll ans1 = 0, ans2 = 0;
  rep(i, 0, 31)rep(j, 0, 31){
    ll water = a * 100 * i + b * 100 * j;
    ll maxsugar = min(f - water, water * e / 100);
    for(ll k = 0; k * c <= maxsugar; k++){
      ll l = (maxsugar - k * c) / d;
      ll sugar = l * d + k * c;
      db con = (db)sugar / (db)(sugar + water);
      if(maxcon <= con){
        maxcon = con;
        ans1 = sugar + water;
        ans2 = sugar;
      }
    }
  }
  cout << ans1 << " " << ans2 << endl;
}
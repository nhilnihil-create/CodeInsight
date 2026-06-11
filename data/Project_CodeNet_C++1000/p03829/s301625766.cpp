#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
/*
void chmin(ll a, ll b){if (a>b){a = b; return true;}return false;}
void chmax(ll a, ll b){if (a<b){a = b; return true;}return false;}
*/

const ll MOD = 1000000007;
const ll INF = 9999999999;

int main() {
  ll N,A,B; cin >>N >>A >>B;
  ll now; cin >>now;
  ll next;
  ll ans = 0;
  for (int i=2; i<=N; i++){
    cin >>next;
    ll walk = A * (next - now);
    ll tele = B;
    ans += min(walk, tele);
    now = next;
  }
  cout <<ans <<endl;
}
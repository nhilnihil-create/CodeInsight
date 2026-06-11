#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

ll W, H;
vector <pair<ll, bool>> P;

int main(){
  cin >> W >> H;
  for (int i = 0; i < W; i++){
    ll A; cin >> A;
    P.push_back({A, false});
  }
  for (int i = 0; i < H; i++){
    ll A; cin >> A;
    P.push_back({A, true});
  }
  sort(P.begin(), P.end());

  ll ans = 0, F = H + 1, T = W + 1;
  for (int i = 0; i < H + W; i++){
    if (P[i].se == false){
      ans += P[i].fi * F; T--;
    }else{
      ans += P[i].fi * T; F--;
    }
  }
  cout << ans << endl;

  return 0;
}

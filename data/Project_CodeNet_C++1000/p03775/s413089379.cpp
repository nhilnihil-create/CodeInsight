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

ll cnt(ll A, ll B){
  ll cnta = 0, cntb = 0;
  while (A > 0){
    cnta++; A /= 10;
  }
  while (B > 0){
    cntb++; B /= 10;
  }
  return max(cnta, cntb);
}

int main(){
  ll N; cin >> N;
  ll ans = 1e9;
  for (ll i = 1; i * i <= N; i++){
    if (N % i != 0) continue;
    ans = min(ans, cnt(i, N / i));
  }
  cout << ans << endl;

  return 0;
}

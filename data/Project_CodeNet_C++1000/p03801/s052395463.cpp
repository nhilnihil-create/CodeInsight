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

int N;
ll A[int(1e5+5)], ans[int(1e5+5)];
Pli P[int(1e5+5)];

int main(){
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> A[i]; P[i] = {A[i], i};
  }
  sort(P, P + N, greater<Pli>());

  int m = N; ll sum = 0, sum2 = 0;
  for (ll i = 0; i < N; i++){
    if (m > P[i].se){
      ans[m] = sum - (P[i].fi * i + sum2);
      m = P[i].se;
      sum2 = sum - P[i].fi * i;
    }
    sum += P[i].fi;
  }
  ans[m] += sum - sum2;

  for (int i = 0; i < N; i++){
    cout << ans[i] << endl;
  }
  return 0;
}

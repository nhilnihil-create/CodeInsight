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
ll T[int(1e5+5)], A[int(1e5+5)];
ll Ht[int(1e5+5)], Ha[int(1e5+5)];

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> T[i];
  for (int i = 1; i <= N; i++) cin >> A[i];

  for (int i = 1; i <= N; i++){
    if (T[i-1] < T[i]) Ht[i] = T[i];
  }
  for (int i = N; i >= 1; i--){
    if (A[i] > A[i+1]) Ha[i] = A[i];
  }


  ll ans = 1;
  for (int i = 1; i <= N; i++){
    if (Ht[i] == 0 && Ha[i] == 0){
      ans *= min(T[i], A[i]);
    }else{
      if (Ht[i] > 0 && Ha[i] > 0 && Ht[i] != Ha[i]){
        ans *= 0;
      }
      if (Ht[i] > 0 && Ha[i] == 0 && T[i] > A[i]){
        ans *= 0;
      }
      if (Ht[i] == 0 && Ha[i] > 0 && A[i] > T[i]){
        ans *= 0;
      }
    }
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}

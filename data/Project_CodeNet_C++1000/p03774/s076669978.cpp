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

int N, M;
ll A[55], B[55], C[55], D[55];
int ans[55];

int Solve(int num){
  ll sum = 1e18;
  for (int i = 1; i <= M; i++){
    if (sum > abs(A[num] - C[i]) + abs(B[num] - D[i])){
      ans[num] = i;
      sum = abs(A[num] - C[i]) + abs(B[num] - D[i]);
    }
  }
  cout << ans[num] << endl;

  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 1; i <= N; i++) cin >> A[i] >> B[i];
  for (int i = 1; i <= M; i++) cin >> C[i] >> D[i];


  for (int i = 1; i <= N; i++) Solve(i);


  return 0;
}

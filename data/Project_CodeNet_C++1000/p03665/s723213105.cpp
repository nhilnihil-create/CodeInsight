#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;

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

int N, P, A[55];
ll DP[55][2];

int main(){
  cin >> N >> P;
  for (int i = 1; i <= N; i++) cin >> A[i];
  DP[0][0] = 1;
  for (int i = 1; i <= N; i++){
    for (int j = 0; j < 2; j++){
      DP[i][j] = DP[i-1][j];
    }
    for (int j = 0; j < 2; j++){
      DP[i][(j + A[i]) % 2] += DP[i-1][j];
    }
  }
  cout << DP[N][P] << endl;

  return 0;
}

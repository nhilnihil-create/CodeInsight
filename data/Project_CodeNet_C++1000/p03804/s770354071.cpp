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
string A[55], B[55];
bool ans = false;

int Solve(int I, int J){
  for (int i = 0; i < M; i++){
    for (int j = 0; j < M; j++){
      if (A[I+i][J+j] != B[i][j]) return 0;
    }
  }
  ans = true;
  return 0;
}

int main(){
  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  for (int i = 0; i <= N - M; i++){
    for (int j = 0; j <= N - M; j++){
      Solve(i,j);
    }
  }

  if (ans) Yes();
  else No();
  return 0;
}

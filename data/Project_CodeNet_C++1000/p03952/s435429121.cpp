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

int N, X, ans[int(2e5+5)];
bool used[int(2e5+5)];

int main(){
  cin >> N >> X;
  if (X == 1 || X == 2 * N - 1){
    No(); return 0;
  }
  Yes();

  if (N == 2){
    for (int i = 1; i <= 3; i++) cout << i << endl;
    return 0;
  }

  ans[N] = X; used[X] = true;
  if (X == 2){
    ans[N + 1] = 1; used[1] = true;
  }else{
    ans[N+1] = 2 * N - 1; used[2*N-1] = true;
    ans[N-1] = 1; used[1] = true;
    ans[N+2] = 2; used[2] = true;
  }

  int now = 1;
  for (int i = 1; i <= 2 * N - 1; i++){
    if (ans[i] > 0) continue;
    while (used[now]) now++;
    ans[i] = now; used[now] = true;
  }

  for (int i = 1; i <= 2 * N - 1; i++) cout << ans[i] << endl;



  return 0;
}

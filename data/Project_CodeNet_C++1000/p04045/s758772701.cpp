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

int N, K;
bool used[10], visited[int(1e5+5)];
vector <int> ans;

int Solve(int num){
  if (num >= N){
    ans.push_back(num);
    return 0;
  }

  visited[num] = true;
  for (int i = 0; i < 10; i++){
    if (used[i]) continue;
    if (visited[num * 10 + i]) continue;
    Solve(num * 10 + i);
  }

  return 0;
}

int main(){
  cin >> N >> K;
  for (int i = 0; i < K; i++){
    int D; cin >> D;
    used[D] = true;
  }
  Solve(0);

  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;

  return 0;
}

/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n, x;
int a[N];
int mn[2001][2001];

int main(){
  scanf("%d %d", &n, &x);
  for(int i = 0; i < n; ++i){
    scanf("%d", a + i);
    mn[0][i] = a[i];
  }
  for(int i = 1; i < n; ++i){
    for(int j = 0; j < n; ++j){
      mn[i][j] = min(mn[i - 1][(j - 1 + n) % n], a[j]);
    }
  }
  ll ans = (ll)1e18;
  for(int s = 0; s < n; ++s){
    ll cur = s * 1ll * x;
    for(int i = 0; i < n; ++i){
      cur += mn[s][i];
    }
    ans = min(ans, cur);
  }
  printf("%lld", ans);
  return 0;
}

//### In The Name Of GOD ###

// %% Remember; (((He))) is The (((Accepter))) %%

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;

#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) / b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 2 * 1000 * 1000 + 200;
const int MAXN = 100 * 1000 + 1;
const int MLOG = 18;
const int NMAX = 1 * 1000;

signed main(){
  IO;
  int n, t;
  cin >> n >> t;
  int  cnt = 0;
  int a[n] = {}, mx[n + 1] = {}, ans = 0;
  vector<int> vec;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = n - 1; i >= 0; i--)
    mx[i] = max(mx[i + 1], a[i]);
  for(int i = 0; i < n - 1; i++){
    // cout << mx[i + 1] << ' ' << a[i] << ' ';
    if(mx[i + 1] - a[i] > ans) ans = mx[i + 1] - a[i], cnt = 1;
    else if(mx[i + 1] - a[i] == ans) cnt++;
  }
  cout << cnt;
}

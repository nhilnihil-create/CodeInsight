#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
ll low[N][N];

int main(){
  fastIO;
  int n;
  ll x;
  cin >> n >> x;
  ll a[n];
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i];
  }
  for(int i = 0 ; i < n; i ++ ){
    low[i][0] = a[i];
    for(int j = 1 ; j < n; j ++ ){
      low[i][j] = min(low[i][j-1], a[(i-j+n) % n]);
    }
  }
  ll res = (ll)1e18;
  ll cur;
  for(int i = 0 ; i < n ; i ++ ){
    cur = i * x;
    for(int j = 0 ; j < n ; j ++ )
      cur += low[j][i];
    res = min(res, cur);
  }
  cout << res;
  return 0;
}
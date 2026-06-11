#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
void dfs(int k, ll distance, vector<vector<pair<int,ll>>> &root, vector<ll> &allDistance){
  allDistance[k] = distance;
  for(auto a : root[k]){
    if(allDistance[a.first] == -1){
      allDistance[a.first] = distance + a.second;
      dfs(a.first, distance + a.second, root, allDistance);
    }
  }
}
int main(){
  int n;
  cin >> n;
  vector<vector<pair<int, ll>>> root(n);
  rep(i, n - 1){
    int a,b,c; // 0 ~
    cin >> a >> b >> c;
    a--; b--;
    root[a].push_back(make_pair(b, c));
    root[b].push_back(make_pair(a, c));
  }
  int q,k;
  cin >> q >> k;
  k--;
  vector<ll> allDistance(n, -1);
  allDistance[k] = 0;
  dfs(k, 0, root, allDistance);
  rep(i, q){
    int x,y;
    cin >> x >> y;
    x--; y--;
    ll ans = 0;
    ans += allDistance[x];
    ans += allDistance[y];
    cout << ans << endl;
  }
}
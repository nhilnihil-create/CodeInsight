#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using PP = pair<int,pair<int,int>>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};
int sy,sx,gy,gx;

int main(){
  int n,m; cin >> n >> m;
  vector<int> a(n),b(n),c(m),d(m);
  rep(i,n) cin >> a[i] >> b[i];
  rep(i,m) cin >> c[i] >> d[i];

  for(int i = 0; i < n; i++){
    int mn = 1<<29, ans = 0;
    for(int j = 0; j < m; j++){
      int dist = abs(a[i] - c[j]) + abs(b[i] - d[j]);
      if(dist < mn){
        mn = dist;
        ans = j;
      }
    }
    cout << ans+1 << endl;
  }
  return 0;
}

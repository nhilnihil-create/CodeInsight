#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
struct edge{
  ll to, cost;
};
ll n,m,r;
const ll INF = 1e18;
const int max_n = 1e4;
ll d[max_n][max_n];
int main(){
  cin >> n >> m >> r;
  vector<ll> v(r);
  for(int i=0 ; i<r ; i++){
    cin >> v[i];
    v[i]--;
  }
  for(int i=0 ; i<n ; i++){
    for(int j=0 ; j<n ; j++){
      d[i][j] = INF;
      if(i==j) d[i][j] = 0;
    }
  }
  for(int i=0 ; i<m ; i++){
    ll x,y,z; cin >> x >> y >> z;
    --x;  --y;
    d[x][y] = d[y][x] = z;
  }
  for(int k=0 ; k<n ; k++){
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
  ll mid = INF;
  sort(v.begin(), v.end());
  do{
    ll kd = 0;
    for(int i=0 ; i+1<r ; i++){
      kd += d[v[i]][v[i+1]];
    }
    mid = min(mid, kd);
  }while(next_permutation(v.begin(), v.end()));
  cout << mid << endl;
  return 0;
}

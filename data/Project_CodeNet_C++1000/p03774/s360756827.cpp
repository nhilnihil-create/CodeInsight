#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m; cin >> n >> m;
  vector<int> a(n),b(n); rep(i,n) cin >> a[i] >> b[i];
  vector<int> c(m),d(m); rep(i,m) cin >> c[i] >> d[i];
  
  rep(i,n){
    vector<pair<int,int>> dist(m);
    rep(j,m){
      int tmp = abs(c[j]-a[i])+abs(d[j]-b[i]);
      dist[j] = make_pair(tmp,j+1);
    }
    sort(dist.begin(),dist.end());
    
    int mini = dist[0].first;
    int check = INF;
    for(auto x : dist)
      if(x.first == mini) check = min(check,x.second);

    cout << check << endl;
  }
  
  return 0;
}

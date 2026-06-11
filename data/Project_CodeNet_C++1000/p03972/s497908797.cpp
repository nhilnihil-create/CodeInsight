#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int W,H;
  cin >> W >> H;
  int p[W],q[H];
  rep(i,W) cin >> p[i];
  rep(i,H) cin >> q[i];
  pair<int, int> cost[W+H];//cost , tate(0) or yoko(1);
  rep(i,W){
    cost[i] = mp(p[i],1);
  }
  rep(i,H){
    cost[i+W] = mp(q[i],0);
  }
  sort(cost, cost+(W+H));
  ll ans=0;
  int num_H=0;
  int num_W=0;
  int num=0;
  rep(i,H+W){
    if(cost[i].second==1){
      num = H + 1 - num_H;
      num_W++;
    }
    else{
      num = W+1-num_W;
      num_H++;
    }
    ans += 1LL*num*cost[i].first;
  }
  cout << ans << endl;
  return 0;
    

}

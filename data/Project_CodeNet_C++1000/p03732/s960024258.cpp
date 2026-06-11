#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1e9;
const int MOD = 1000000007;

 
int main() {
  ll n,w;
  cin >> n >> w;
  vector<deque<ll>> mp(4,deque<ll>());
  ll w_ = 0;
  rep(i,n){
    int a,b;
    cin >> a >> b;
    if(i==0) {
      w_ = a;
      mp.at(0).emplace_back(b);
    }else{
      mp.at(a-w_).emplace_back(b);
    }
  }
  
  rep(i,4){
    sort(mp[i].begin(),mp[i].end(),greater<ll>());
  }
  
  rep(i,4){
    rep(j,(int)(mp[i].size())-1){
      mp[i][j+1] += mp[i][j];
    }
  }
  
  rep(i,4){
    mp[i].push_front(0);
  }
  
  /*rep(i,4){
    rep(j,(int)(mp[i].size())){
      cout << mp[i][j] << " ";
    }
    cout << endl;
  }*/
  
  ll ans = 0;
  rep(i,(int)(mp[0].size())){
    rep(j,(int)(mp[1].size())){
      rep(k,(int)(mp[2].size())){
        rep(l,(int)(mp[3].size())){
          if(i*w_+j*(w_+1)+k*(w_+2)+l*(w_+3) > w) continue;
          ans = max(ans,mp[0][i]+mp[1][j]+mp[2][k]+mp[3][l]);
        }
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}




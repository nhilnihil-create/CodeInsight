#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)

ll W,H;
vector<pair<ll,bool> > r;//コスト,縦か横(0=縦)

int main(){
  cin >> W >> H;
  rep(i,W){
    ll ptmp;
    cin >> ptmp;
    r.push_back(make_pair(ptmp,1));
  }

  rep(i,H){
    ll qtmp;
    cin >> qtmp;
    r.push_back(make_pair(qtmp,0));
  }

  sort(all(r));

  ll yok=0,tat=0;
  ll ans=0;

  rep(i,H+W){
    if(r[i].second){//横の辺なら
      ans += r[i].first*(H+1-tat);
      yok++;
    }else{
      ans += r[i].first*(W+1-yok);
      tat++;
    }
  }
  cout << ans << endl;
}
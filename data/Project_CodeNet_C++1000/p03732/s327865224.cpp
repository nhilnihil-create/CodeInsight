#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,w;cin>>n>>w;
  ll miw=1e9,maw=0;
  vector<vector<ll>>val(4),vsum(4);
  vector<ll>we(n),va(n);
  rep(i,n){
    cin>>we[i]>>va[i];
    chmin(miw,we[i]);
    chmax(maw,we[i]);
  }
  rep(i,n){
    val[we[i]-miw].push_back(va[i]);
  }

  rep(i,4)sort(all(val[i]),greater<ll>());
  rep(i,4)vsum[i].push_back(0);

  rep(i,4)rep(j,val[i].size())vsum[i].push_back(vsum[i][j]+val[i][j]);
  ll res=0;
  rep(i,vsum[0].size()){
    rep(j,vsum[1].size()){
      rep(k,vsum[2].size()){
        rep(l,vsum[3].size()){
          ll tw=i*miw+j*(miw+1)+k*(miw+2)+l*(miw+3);
          if(tw>w)continue;
          ll tv=vsum[0][i]+vsum[1][j]+vsum[2][k]+vsum[3][l];
          chmax(res,tv);

        }

      }

    }
  }
  cout<<res<<endl;
  



  return 0;

}

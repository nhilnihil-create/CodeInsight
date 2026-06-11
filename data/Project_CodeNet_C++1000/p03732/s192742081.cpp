#include <bits/stdc++.h>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define FOR(i,a,b) for (ll i=(a);i<(ll)b; i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define INF 1LL << 60
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;
const long long MOD=1000000007;

// vector<p> cut(M);
// cut[i].second
// cut[i].first;
// REP(i,M){
//     int a,b;cin>>a>>b;
//     cut[i] = make_pair(b,a);//last first の順番
// }
// for(int i=0; i<N;i++){
// }
// sort(cut.begin(),cut.end()); //sort
// char '' str ""
int main(void)
{
    int N,W;cin>>N>>W;
    vector<vector<ll> > v(4);
    vector<vector<ll> > sv(4);
    ll w1, v1;
    cin>>w1>>v1;
    v[0].push_back(v1);
    for(int i=1;i<N;i++){
      ll ww,vv; cin>>ww>>vv;
      v[ww-w1].push_back(vv);
    }
    for(int j=0;j<4;j++){
      sort(v[j].rbegin(), v[j].rend());
      sv[j].push_back(0);
    }

    for(int j=0;j<4;j++){
      for(int i=0;i<v[j].size();i++){
        sv[j].push_back(sv[j][i]+v[j][i]);
      }
    }

    ll ans=0;
    for(int a=0;a<=v[0].size();a++){
      for(int b=0;b<=v[1].size();b++){
        for(int c=0;c<=v[2].size();c++){
          for(int d=0;d<=v[3].size();d++){

            ll temp_w = (a+b+c+d)*w1 + b + c*2 + d*3;
            if(temp_w <= W) ans = max(ans, sv[0][a]+sv[1][b]+sv[2][c]+sv[3][d]);

          }
        }
      }
    }

    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=(1LL<<61)-1;



int main(){
    ll N,W; cin >> N >> W;
    vector<P> vw(N);
    ll w0 = 0;
    rep(i,N){
        int v,w; cin >> w >> v;
        if(i==0) w0 = w;
        w-= w0;
        vw[i] = make_pair(v,w);
    }

    sort(vw.begin(),vw.end(),greater<P>());
    vector<vector<ll> > sum(5,vector<ll>(110,0));
    int num[5]={0};
    rep(i,N){
        rep(j,4){
            if(vw[i].second==j){
                num[j]++;
                sum[j][num[j]] = sum[j][num[j]-1]+vw[i].first;
            }
        }
    }
    
    ll ans = -1;
    rep(i,num[0]+1){
        rep(j,num[1]+1){
            rep(k,num[2]+1){
                rep(l,num[3]+1){
                    if(w0*(i+j+k+l) + j*1+k*2+l*3 <= W) chmax(ans, sum[0][i]+sum[1][j]+sum[2][k]+sum[3][l]);
                }
            }
        }
    }
    cout << ans << endl;
}
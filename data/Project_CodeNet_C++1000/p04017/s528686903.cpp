#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using P = pair<ll,ll>;
using grid = vector<vector<int>>;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
const int INF = 1<<30;
const ll mod = 998244353LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll N,L,Q;
vector<ll> x;
ll rnex[30][100005];

int main() {
    cin>>N;
    x.resize(N);
    rep(i,N) cin>>x[i];
    cin>>L;
    rep(i,N){
        rep(j,30) {
            rnex[j][i] = INF;
        }
    }
    rep(i,N){
        if(i!=N-1) {
            auto rite = upper_bound(x.begin(),x.end(),x[i]+L);
            rnex[0][i] = rite-x.begin()-1;
        }
    }
    rep(i,29){
        rep(j,N){
            if(rnex[i][j]!=INF) rnex[i+1][j] = rnex[i][rnex[i][j]];
        }
    }
    cin>>Q;
    rep(i,Q){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        ll s = min(a,b);
        ll t = max(a,b);
        ll l = 0, r = N;
        while(r-l>1){
            ll mid = (r+l)/2;
            ll L = s;
            rep(i,30){
                if(mid&(1<<i)&&L!=INF) {
                    L = rnex[i][L];
                }
            }
            if(L<t) l = mid;
            else r = mid;
        }
        cout<<r<<endl;
    }
}
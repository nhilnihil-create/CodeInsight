#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
struct point{ll start,rest,color;};

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main() {
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    rep(i,M){
        ll a,b;
        cin >> a >> b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll Q;
    cin >> Q;
    vector<ll> v(Q),d(Q),c(Q);
    rep(i,Q){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    queue<point> que;
    vector<ll> ans(N,0),range(N,0);
    for (ll i=Q-1;i>=0;i--){
        if (d[i]!=0){
            que.push(point{v[i],d[i],c[i]});
        }
        chmax(range[v[i]],d[i]);
        if (ans[v[i]]==0){
            ans[v[i]]=c[i];
        }
        while(!que.empty()){
            point p=que.front();
            que.pop();
            for (auto x:G[p.start]){
                if (ans[x]==0){
                    ans[x]=p.color;
                }
                if (p.rest>1&&chmax(range[x],p.rest-1)){
                    que.push(point{x,p.rest-1,p.color});
                }
            }
        }
    }
    rep(i,N){
        cout << ans[i] << endl;
    }
}
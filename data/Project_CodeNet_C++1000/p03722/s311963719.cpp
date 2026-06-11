#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main()
{
    const ll INF = -1e15;
    struct edge{
        ll from;
        ll to;
        ll cost;
    };
    ll n, m;
    cin >> n >> m;
    vector<edge>edges(m);
    rep(i,m){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {a, b, c};
    }
    vector<ll>ans(n, INF);
    ans[0] = 0;
    rep(i,n - 1){
        rep(j, m){
            if(ans[edges[j].from] != INF){ 
                ans[edges[j].to] = max(ans[edges[j].to], ans[edges[j].from] + edges[j].cost);
            }
        }
    }
    bool ok = true;
    rep(j,m){
        ll a = ans[n - 1];
        if(ans[edges[j].from] != INF){
            ans[edges[j].to] = max(ans[edges[j].to], ans[edges[j].from] + edges[j].cost);
        }
        if(a < ans[n - 1]) ok = false;
    }
    if(!ok) cout << "inf" << endl;
    else cout << ans[n - 1] << endl;
    return 0;
}


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const int MOD=1e9+7;
const ll INF=2e18;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<P>> r(n); 
    rep(i,n-1) {
        ll a,b,c;
        cin >> a >> b >> c;
        r[a-1].push_back({b-1,c});
        r[b-1].push_back({a-1,c});
    } 
    int q,k;
    cin >> q >> k;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({k-1,0});
    vector<ll> cost(n,INF);
    cost[k-1]=0;
    while (!pq.empty()) {
        P p=pq.top();
        pq.pop();
        int now=p.first;
        rep(i,r[now].size()) {
            int next=r[now][i].first;
            ll nc=cost[now]+r[now][i].second;
            if (cost[next]>nc) {
                cost[next]=nc;
                pq.push({next,nc});
            }
        }
    }
    rep(i,q) {
        int x,y;
        cin >> x >> y;
        cout << cost[x-1]+cost[y-1] << endl;
    }
    return 0;   
}

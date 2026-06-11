#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vint;
typedef vector< vector<ll> > vvint;

#define rep(i,n) for(ll i=0;i<n;i++)
#define repf(i,f,n) for(ll i=f;i<n;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define mp make_pair
#define mt make_tuple
#define ALL(obj) (obj).begin(), (obj).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int dy[]={0, 0, 1, -1, 1, -1, -1, 1};
int dx[]={1, -1, 0, 0, 1, 1, -1, -1};


int main() {
    cout<<fixed<<setprecision(10);

    ll n,m; cin>>n>>m;
    vvint edges(n);
    rep(i,m){
        ll a,b; cin>>a>>b;
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    set<ll> used;
    vint v1, v2;
    v1.push_back(0);
    v2.push_back(edges[0].front());
    used.insert(0);
    used.insert(edges[0].front());

    while(true){
        bool ok = true;

        for(auto e:edges[v1.back()]){
            if(used.count(e)) continue;
            v1.push_back(e);
            used.insert(e);
            ok = false;
            break;
        }

        if(ok) break;
        else continue;
    }

    while(true){
        bool ok = true;

        for(auto e:edges[v2.back()]){
            if(used.count(e)) continue;
            v2.push_back(e);
            used.insert(e);
            ok = false;
            break;
        }

        if(ok) break;
        else continue;
    }

    cout<<v1.size()+v2.size()<<endl;
    repr(i, v1.size()) cout<<v1[i]+1<<" ";
    rep(i, v2.size()) cout<<v2[i]+1<<" ";
    cout<<endl;

    return 0;

}
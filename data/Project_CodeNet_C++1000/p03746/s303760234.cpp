#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

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

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> G(N+1);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> ans;
    vector<bool> visited(N+1,false);
    visited[1]=true;
    ans.push_back(1);
    int now=1;
    bool ok=false,once=true;
    while(!ok){
        bool changed=true;
        for (auto v:G[now]){
            if (!visited[v]){
                changed=false;
                visited[v]=true;
                ans.push_back(v);
                now=v;
                break;
            }
        }
        if (once&&changed){
            reverse(ans.begin(),ans.end());
            once=false;
            now=1;
            for (auto v:G[now]){
                if (!visited[v]){
                    changed=false;
                    visited[v]=true;
                    ans.push_back(v);
                    now=v;
                    break;
                }
            }
        }
        if (changed){
            ok=true;
        }
    }
    int s=ans.size();
    cout << s << endl;
    rep(i,s){
        cout << ans[i];
        if (i!=s-1){
            cout << ' ';
        }
        else {
            cout << endl;
        }
    }
}
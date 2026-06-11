#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

vector<ll> adj[100010];
bool visit[100010];
ll pointer[100010];

void solve(){

    ll n,m;
    cin >> n >> m;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].eb(b);
        adj[b].eb(a);
    }


    rep(i,n){
        visit[i]=false;
        pointer[i]=-1;
    }

    ll s = 0;
    ll g = adj[0][0];
    visit[s]=true;
    visit[g]=true;
    pointer[s]=g;
    bool b = true;
    //始点か終点が条件を満たしていないならtrue
    while(b){
        b=false;

        //cout << "s:" << s << " g:" << g << endl;

        for(auto e:adj[s]){
            if(visit[e]==false){
                visit[e]=true;
                pointer[e]=s;
                s=e;
                break;
            }
        }

        for(auto e:adj[g]){
            if(visit[e]==false){
                visit[e]=true;
                pointer[g]=e;
                g=e;
                break;
            }
        }

        for(auto e:adj[s]){
            if(visit[e]==false) b=true;
        }
        for(auto e:adj[g]){
            if(visit[e]==false) b=true;
        }
    }

    ll count = 1;
    ll p = s;
    //cout << p+1 << " ";
    while(true){
        if(pointer[p]==-1) break;
        //cout << pointer[p]+1 << " ";
        p = pointer[p];
        count++;
    }

    cout << count << endl;
    p = s;
    cout << p+1 << " ";
    while(true){
        if(pointer[p]==-1) break;
        cout << pointer[p]+1 << " ";
        p = pointer[p];
        count++;
    }
    

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}

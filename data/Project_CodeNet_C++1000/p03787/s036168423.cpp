//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}



const int N = 200005;
int n, state[N];
vector<int> adj[N], affected;
bool impossible;


void dfs(int v){
    affected.pb(v);
    for(auto vv : adj[v])
        if(state[vv] == -1){
            state[vv] = 1^state[v];
            dfs(vv);
        }
        else if(state[vv] == state[v]){
            impossible = true;
        }
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int e;
    cin>>n>>e;
    while(e--){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    memset(state, -1, sizeof(state));
    ll x = 0, y = 0, z = 0;
    for(int i=1;i<=n;i++){

        if(state[i] != -1)  continue;
        if(adj[i].empty()){
            z++;    continue;
        }

        state[i] = 0;
        affected.clear();
        impossible = false;
        dfs(i);

        if(!impossible){
            x++;
            continue;
        }

        while(!affected.empty()){
            state[affected.back()] = -1;
            affected.pop_back();
        }

        state[i] = 1;
        affected.clear();
        impossible = false;
        dfs(i);

        if(impossible){
            y++;
        }
        else{
            x++;
        }
    }

// cout<<x<<" "<<y<<" "<<z<<endl;

    ll ans = x*(2*x+y) + y*(x+y) + z*n + (n-z)*z;;
    cout<<ans;
    return 0;
}







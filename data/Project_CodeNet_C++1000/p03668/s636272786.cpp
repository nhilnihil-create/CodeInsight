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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
 
ll pwr(ll base, ll p, ll mod=MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
 
 
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}


const int N = 200002;
int n;
vector<int> adj[N];


int dfs(int v, int par){
	int ans = 0;
	for(auto vv : adj[v])
		if(vv != par)
			ans ^= 1+dfs(vv, v);
// cout<<"dfs "<<v<<" returns "<<ans<<endl;
	return ans;
}

 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int e = n-1;
    while(e--){
    	int a, b;
    	cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    if(dfs(1, -1) == 0)	cout<<"Bob";
    else	cout<<"Alice";
    return 0;
}





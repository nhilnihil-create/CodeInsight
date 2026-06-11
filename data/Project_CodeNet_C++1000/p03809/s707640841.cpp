/// Be Kind :)
#include <bits/stdc++.h>
using namespace std;
 
#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("Os")

/*				Who knew evil girls had the prettiest face					*/

/*				We pop out at your party, I'm with the gang
				And it's gon' be a robbery, so tuck ya chain
				I'm a killer girl, I'm sorry, but I cannot change
				We ain't aiming for your body, shots hit you brain
				We come from poverty, man, we ain't have a thing
				It's a lot of animosity, but they won't say my name
				Them killers rock with me, lil' nigga, don't get banged
				'Cause they'll do that job for me while I hop on a plane	*/

/*				I take you to the candy shop								*/

/*				Baby, let me put your panties to the side
				I'ma make you feel alright
				'Cause I'ma give you what you need, yeah					*/

/*				Ooooh ooh, it's me, myself and I
				Solo ride until I die, 'cause I got me for life				*/

/*				So I ball So hard, muh'fuckas wanna find me					*/

/*				Bitch, where you when I was walkin'?
				Now I run the game, got the whole world talkin'				*/
 
/*				Niggas been counting me out
				I'm counting my bullets, I'm loading my clips
				I'm writing down names, I'm making a list					*/

/*				Fuck your friendship, I meant it							*/

/*				The Chanel or Balenciaga, Louis and Vuitton
				She know I got Fendi, Prada when I hit Milan				*/

/*				I ran away, I don't think I'm coming back home				*/
 
#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
 
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const ll maxn=1e5+10, maxm=1e5+10, lg=21, mod=1e9+7, inf=1e18;


ll n,a[maxn],pp[maxn];
vector<ll> g[maxn];

void dfs(ll v,ll p=0){
	if(SZ(g[v])==1){ pp[v]=a[v]; return; }
	ll sum=0,mxm=0;
	for(auto u:g[v])if(u!=p){ dfs(u,v);
		sum+=pp[u];
		mxm=max(mxm,pp[u]);
	}
	if(sum<a[v] || 2*a[v]<sum || a[v]<mxm){
		cout<<"NO";
		exit(0);
	}
	pp[v]=2*a[v]-sum;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		ll v,u; cin>>v>>u;
		g[v].pb(u), g[u].pb(v);
	}
	if(n==2) return cout<<(a[1]==a[2] ? "YES":"NO"),0;
	ll v=0; for(int i=1;i<=n;i++)if(SZ(g[i])>1) v=i;
	dfs(v);
	if(pp[v]) return cout<<"NO",0;
	cout<<"YES";
	
	return 0;
}



 

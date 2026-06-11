#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define pb push_back
#define pi pair<ll,ll>
#define ff first
#define ss second
#define MAX 200550
const ll MOD = 1000000007;

vector<int>g[MAX];
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	int t=1;
//	cin>>t;
	while(t--){
	 int n,m;
	 cin>>n>>m;
	 
	 while(m--)
	 {
	 	int u,v;
	 	cin>>u>>v;
	 	
	 	g[u].pb(v);
	 	g[v].pb(u);
	 }
	 for(auto elm:g[1])
	 {
	 	for(auto f:g[elm])
	 	{
	 		if(f==n)
	 		{
	 			cout<<"POSSIBLE\n";
	 			return 0;
			 }
		 }
	 }
	 cout<<"IMPOSSIBLE\n";
	}		
}
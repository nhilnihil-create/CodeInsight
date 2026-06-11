#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
#define ordered_set tree < pairs ,  null_type , greater<pairs>,  rb_tree_tag ,  tree_order_statistics_node_update > 
#define ll long long
#define lld long double
#define vc vector<ll>
const ll MOD=(1e9 +7);
typedef pair<ll,ll>pairs;
ll power(ll a, ll b){ll res=1;a=a%MOD;while(b>0){if(b&1){res=(res*a)%MOD;b--;}a=(a*a)%MOD;b>>=1;}
    return res;}

int main() {
	// your code goes here
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	ll t,m,n,i,j,k,c,f,x,y;
	cin>>n>>m;f=0;
	vc red(n+1),balls(n+1,1);
	red[1]=1;
	ll cnt=0;
	for(i=1;i<=m;i++)
	{
	    cin>>x>>y;
	    if(red[x])red[y]=1;
	    balls[x]--;balls[y]++;
	    if(balls[x]==0)red[x]=0;
	}
	for(i=1;i<=n;i++)cnt+=red[i];
	cout<<cnt;
	return 0;
}

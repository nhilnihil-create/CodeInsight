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
	ll t,a,b,n,i,j,k,c,f;
	cin>>a>>b;
	ll mn,mx;
	mn=min(a,b);mx=max(a,b);
	ll cnt=max(-mn,0ll)-max(-mx+1,0ll);
	if(mx>=0&&mn<=0)cout<<"Zero";
	else if(cnt&1)cout<<"Negative";
	else cout<<"Positive";
	return 0;
}

#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

ll n,av;
vector<ll> a;
ll dp[60][3000][60];

ll f(int i, int su, int cnt){
	if(i== n){
		return(su == cnt*av);
	}
	if(dp[i][su][cnt] != -1){
		return dp[i][su][cnt];
	}

	ll ans = 0;
	ans += f(i+1,su,cnt);
	ans += f(i+1,su+a[i],cnt+1);
	dp[i][su][cnt] = ans;
	return ans;
}


int main(){
	fastread;
	cin>>n>>av;
	a.resize(n);
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<f(0,0,0)-1<<endl;

	return 0;
}

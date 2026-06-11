#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,M=1e9+7;
string s;
int dp[5002][5003];
int calc(int i,int p){
	if(p==n)return (i==s.size())?1:0;
	int &ret=dp[i][p];
	if(ret!=-1)return ret;
	ret=(2ll*calc(i+1,p+1)+calc(max(0,i-1),p+1))%M;
	return ret;
}
ll pp(ll n,ll p ){
	if(!p)return 1;
	ll ret=pp(n,p/2);
	if(p&1)return ((ret*ret)%M*n)%M;
	return (ret*ret)%M;
}
int main() {
	cin>>n>>s;
	memset(dp,-1,sizeof dp);
	ll ans=calc(0,0);
	ll inv=pp(2,s.size());
	ans=(ans*pp(inv,M-2))%M;
	cout<<ans<<endl;
	
	return 0;
}
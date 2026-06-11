#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
ll dp[100009][11];
vector<ll> nex[100009],ma(100009),cen(100009),r(100009),col(100009);
void paint(ll cc, ll cr, ll tm){
	if(dp[cc][cr]==0){
		for(int i=cr;i>=0;i--){
			if(dp[cc][i]==0){
				dp[cc][i]=tm+1;
			}
		}
		//cout<<cc<<" "<<cr<<" "<<tm<<endl;
		if(cr>0){
			for(int i=0;i<nex[cc].size();i++){
				paint(nex[cc][i], cr-1, tm);
			}
		}
	}
	return;
}
	
int main(){
	ll n,m,q;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll tmpa, tmpb;
		cin>>tmpa>>tmpb;
		nex[tmpa].pb(tmpb);
		nex[tmpb].pb(tmpa);
	}
	cin>>q;
	for(int i=0;i<=100000;i++){
		for(int j=0;j<=10;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>cen[i]>>r[i]>>col[i];
	}
	for(int i=q;i>=1;i--){
		paint(cen[i],r[i],i);
	}
	for(int i=1;i<=n;i++){
		if(dp[i][0]==0){cout<<0<<endl;}
		else{ cout<<col[ dp[i][0] -1 ]<<endl;}
	}
	return 0;
}
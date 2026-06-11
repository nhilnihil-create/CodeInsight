#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n,m,a[maxn],chafen[maxn],vis[maxn],ps1[maxn],ps2[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0;
	for(int i=0;i<n-1;i++){
		int s=a[i],t=a[i+1];
		if(t>s){
			sum+=t-s;
			++vis[s+1];
			--vis[t+1];
			chafen[s+1]+=s+1;
			chafen[t+1]-=s+1;
		}else{
			sum+=m-s+t;
			++vis[s+1];
			++vis[1];
			--vis[t+1];
			chafen[s+1]+=s+1;
			chafen[1]-=m-s-1;
			chafen[t+1]+=m-s-1;
		}
	}
	for(int i=1;i<=m;i++){
		ps1[i]=ps1[i-1]+vis[i];
	}
	for(int i=1;i<=m;i++){
		ps2[i]=ps2[i-1]+chafen[i];
	}
//	for(int i=1;i<=m;i++){
//		cout<<ps1[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=m;i++){
//		cout<<ps2[i]<<" ";
//	}
//	cout<<endl;
	int mx=0;
	for(int i=1;i<=m;i++){
		mx=max(mx,i*ps1[i]-ps2[i]);
	}
	cout<<sum-mx<<endl;
	return 0;
}
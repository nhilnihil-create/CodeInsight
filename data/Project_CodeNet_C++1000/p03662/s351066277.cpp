#include <bits/stdc++.h>
#define int long long
#define P pair<int,int>
#define inf (int)(3e18)
#define mod (int)(1e9+7)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int n;
vector<int>G[114514];
int fe[114514],snu[114514];
void dfs(int x,bool b){
	for(int i:G[x]){
		if(b&&fe[i])continue;
		if(!b&&snu[i])continue;
		if(b){
			fe[i]=fe[x]+1;
		}else {
			snu[i]=snu[x]+1;
		}
		dfs(i,b);
	}
}
signed main(){
	cin>>n;
	rep(i,n-1){
		int a,b;cin>>a>>b;a--;b--;
		G[a].push_back(b);G[b].push_back(a);
	}
	fe[0]=1;snu[n-1]=1;
	dfs(0,1);dfs(n-1,0);
	int f=0,s=0;
	rep(i,n){
		if(fe[i]<=snu[i])f++;
		else s++;
	}
	if(f>s){
		cout<<"Fennec"<<endl;	
	}else {
		cout<<"Snuke"<<endl;
	}
}

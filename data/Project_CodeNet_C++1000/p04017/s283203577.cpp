#include<bits/stdc++.h>
using namespace std;
int n,l,q,u,v;
int a[100055];
int P[100055][20];
signed main(){
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>l;
	for(int i=1;i<=n;i++){
		int far=a[i]+l;
		int k=lower_bound(a+1,a+1+n,far)-a;
		if(a[k]>far||k==n+1) k--;
		P[i][0]=k;
	}
	for(int j=1;1<<j<=n;j++) for(int i=1;i<=n;i++) P[i][j]=P[P[i][j-1]][j-1];
	cin>>q;
	while(q--){
		cin>>u>>v;
		if(v<u) swap(u,v);
		int lg=log2(n),ans=0;
		for(int i=lg;i>=0;i--){
			if(P[u][i]<v){
				ans+=(1<<i);
				u=P[u][i];
			}
		}
		cout<<ans+1<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;

int a[301][301];
bool vis[301][301];
int cnt[301];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	int ans=1e9;
	for(int i=1;i<=m;i++){
		memset(cnt,0,sizeof cnt);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++)
				if(!vis[j][k]){
					cnt[a[j][k]]++;
					break;
				}
		}
		int x,y=0;
		for(int j=1;j<=m;j++)
			if(y<cnt[j])
				x=j,y=cnt[j];
		ans=min(ans,y);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++)
				if(a[j][k]==x){
					vis[j][k]=true;
					break;
				}
		}
	}
	cout<<ans<<endl;
	
}

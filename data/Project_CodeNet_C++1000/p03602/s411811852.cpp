#include<bits/stdc++.h>
using namespace std;
namespace Kitahara_Kazusa{
	int n;
	int dis[1010][1010],vis[1010][1010];
	void solve(){
		ios::sync_with_stdio(false);
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				cin>>dis[i][j];
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					if(i!=j&&j!=k&&i!=k){
						if(dis[i][j]+dis[j][k]<dis[i][k]){
							puts("-1");
							exit(0);
						}
						else if(dis[i][j]+dis[j][k]==dis[i][k]){
							vis[i][k]=true;
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;++i)
			for(int j=i+1;j<=n;++j){
				if(!vis[i][j])ans=ans+dis[i][j];
			}
		cout<<ans<<endl;
	}
}
int main(){
	Kitahara_Kazusa::solve();
	return 0;
} 
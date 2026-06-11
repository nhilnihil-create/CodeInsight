#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
int n;
int a[334][334],ans=0;
signed main(){
	cin>>n;
	rep(i,n)rep(j,n)cin>>a[i][j];
	rep(i,n){
		for(int j=i+1;j<n;j++){
			bool f=0;
			rep(k,n){
				if(i!=k&&j!=k){
					if(a[i][k]+a[k][j]<a[i][j]){
						puts("-1");
						return 0;
					}
					if(a[i][k]+a[k][j]==a[i][j]){
						f=1;
						break;
					}
				}
			}
			if(!f)ans+=a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}

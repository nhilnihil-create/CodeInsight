
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
const int INF=1000000;
int dp1[5005][5005]={};
int dp2[5005][5005]={};
int main() {
	int n,k;
	int a[5002];
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a,a+n);
	dp1[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=0;j<5000;++j){
			if(dp1[i-1][j]){
				dp1[i][min(5005,j+a[i])]=1;
				dp1[i][j]=1;
			}
		}
	}
	for(int i=0;i<=n;++i){
		for(int j=1;j<=5005;++j)dp1[i][j]+=dp1[i][j-1];
	}
	dp2[n+1][0]=1;
	for(int i=n;i>0;--i){
		for(int j=0;j<5000;++j){
			if(dp2[i+1][j]){
				dp2[i][min(5005,j+a[i])]=1;
				dp2[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n+1;++i){
		for(int j=1;j<=5005;++j)dp2[i][j]+=dp2[i][j-1];
	}
	ll ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<k;++j){
			int h=k-j;
			if(dp1[i-1][j]-dp1[i-1][j-1]&&dp2[i+1][h-1]-dp2[i+1][max(h-a[i]-1,-1)]){
//				cout<<i<<" "<<j<<endl;
				ans++;
				break;
			}
		}
	}
	cout<<n-ans<<endl;
	return 0;
}

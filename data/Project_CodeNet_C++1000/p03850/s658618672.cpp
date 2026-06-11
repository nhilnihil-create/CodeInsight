//ΔARC066E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
const LL INF = 1e18;
int n,a[N],op[N];
LL dp[N][3];
int main()
{
	int i,x;
	char ch[5];
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%s",a+i,ch);
		op[i+1]=(ch[0]=='-');
	}
	scanf("%d",a+n);
	dp[1][0]=a[1];
	dp[1][1]=-INF;
	dp[1][2]=-INF;
	for(i=2;i<=n;i=i+1){
		if(op[i]){
			dp[i][0]=max(max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]),dp[i-1][2]-a[i]);
			dp[i][1]=max(max(dp[i-1][0]-a[i],dp[i-1][1]+a[i]),dp[i-1][2]+a[i]);
			dp[i][2]=max(dp[i-1][1]+a[i],dp[i-1][2]+a[i]);
		}
		else{
			dp[i][0]=max(max(dp[i-1][0]+a[i],dp[i-1][1]+a[i]),dp[i-1][2]+a[i]);
			dp[i][1]=dp[i-1][1]-a[i];
			dp[i][2]=dp[i-1][2]+a[i];
		}
	}
	cout<<max(max(dp[n][0],dp[n][1]),dp[n][2]);
	return 0;
}
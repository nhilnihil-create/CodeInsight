#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <iostream>
#define INF 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll a[100005];
int op[100005];
ll dp[100005][10];

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%*c",&a[i]);
		if(i!=n-1){
			char c;
			scanf("%c%*c",&c);
			if(c=='+')op[i+1]=1;
			else op[i+1]=-1;
		}
	}
	op[0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<10;j++){
			dp[i][j]=-(ll)(INF)*n;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<9;j++){
			int cp=op[i];
			if(j%2==1)cp=-cp;
			dp[i+1][j]=max(dp[i+1][j],(ll)dp[i][j]+a[i]*cp);
			if(op[i]==-1){
				dp[i+1][j+1]=max(dp[i+1][j+1],(ll)dp[i][j]+a[i]*cp);
			}
			if(j>0){
				dp[i+1][j-1]=max(dp[i+1][j-1],(ll)dp[i][j]+a[i]*cp);
			}
		}
	}
	printf("%lld\n",dp[n][0]);
	return 0;
}

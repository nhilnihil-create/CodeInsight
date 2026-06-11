#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int dp[N][23];
int n,L;
int a[N];
int q,x,y;
int ef(int id,int v){
	int l=id,r=n,ans=id;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=v)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
void cl(){ // 
	for(int i=1;i<=n;i++)dp[i][0]=ef(i,a[i]+L);
	for(int j=1;j<23;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
}
int js(int x,int y){
	int ans=0,pos=x;
	for(int i=22;i>=0;i--){
		if(dp[pos][i]<y){
			pos=dp[pos][i];
			ans+=(1<<i);
		}
	}
	ans++;
	return ans;
}
int main()
{
	//freopen("H:\\c++1\\in.txt","r",stdin);
	//freopen("H:\\c++1\\out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&L);
	scanf("%d",&q);
	cl();
	while(q--){
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		printf("%d\n",js(x,y));
	}
	return 0;
}
/*
9
1 3 6 13 15 18 19 29 31
10
4
1 8
7 3
6 7
8 5
*/
/*
4
2
1
2
*/
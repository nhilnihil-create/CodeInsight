
#include <iostream>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<map>
#include<cstdio>
using namespace std;
#define rep(i,a) for(int i=0;i<a;i++)
#define mp make_pair
#define pb push_back
#define P pair<int,int>
#define ll __int64
//#define ll long long
const int INF=111111111;
int n,k;
int a[111111];
const int N=5005;
const int K=5005;
bool dp[N][K];
int t[N];

void dynamic_programming(int x){
	rep(i,N)rep(j,K)dp[i][j]=0;
	int pos=0;
	rep(i,n)if(x!=i)t[pos++]=a[i];

	dp[0][0]=1;
	rep(i,pos){
		rep(j,K+1){
			if(dp[i][j]){
				if(j+t[i]<=K){dp[i+1][j+t[i]]=1;}
				dp[i+1][j]=1;
			}
		}
	}

	//rep(i,k+1)if(dp[pos][i])cout<<i<<" ";
}

int main(){
	cin>>n>>k;
	rep(i,n)cin>>a[i];
	sort(a,a+n);

	int ans=0;
	int l=-1,r=n,mid=(l+r)/2;

	while(r-l>1){
		//cout<<mid<<endl;
		bool is=0;
		dynamic_programming(mid);
		if(k-a[mid]<=0)is=1;
		else for(int j=k-a[mid];j<k;j++)if(dp[n-1][j])is=1;
		if(!is)l=mid;//不要
		else r=mid;
		mid=(r+l)/2;
	}

	cout<<r<<endl;
	return 0;
}

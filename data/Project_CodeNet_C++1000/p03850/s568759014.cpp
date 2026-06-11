/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=100005;
int n;
int a[maxn];
ll ans;
ll sum[maxn],sum2[maxn];
char c[2];
 
int main(){
	scanf("%d",&n);
	int op=1;
	rep(i,n){
		scanf("%d",&a[i]);
		a[i]*=op;
		if(i!=n-1){
			scanf("%s",c);
			if(c[0]=='-')op=-1;
			else op=1;
		}
	}
	for(int i=n-1;i>=0;i--)sum[i]=sum[i+1]+abs(a[i]);
	for(int i=n-1;i>=0;i--){
		if(a[i]<0)sum2[i]=0;
		else sum2[i]=sum2[i+1]+a[i];
	}
	ll cur=0;
	rep(i,n){
		cur+=a[i];
		if(a[i]<0)ans=max(ans,cur+sum[i+1]-2*sum2[i+1]);
	}
	ans=max(ans,cur);
	printf("%lld",ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/
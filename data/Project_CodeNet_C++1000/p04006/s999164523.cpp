#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#define inf 0x7f7f7f7f
using namespace std;
typedef long long ll;
#define maxn 5000010

void read(ll &x){
	int f=1;x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0';ch=getchar();}
	x*=f;
} 

ll n,a[maxn],x;
ll dp[3000][3000];
int main(){
	read(n),read(x);
	for(int i=1;i<=n;i++){
		read(a[i]);
		dp[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<n;j++){
			int t=i-j;
			if(t<=0){
				t+=n;
			}
			dp[i][j]=min(dp[i][j-1],a[t]);
		}
	}
	ll ans=1e18;
	for(int i=0;i<n;i++){
		ll sum=0;
		for(int j=1;j<=n;j++){
			sum+=dp[j][i];
		}
		ans=min(ans,sum+i*x);
	}
	cout<<ans<<endl;
}
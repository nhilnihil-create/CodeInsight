#include<bits/stdc++.h>
#define ll long long
#define N 1000005
#define M 10005
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f=(ch=='-')?-1:1,ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f*x;
}
int n,w[N],g[N]={2};
bool check(int mid){
	int flag=0;
	for(int i=1;i<n+n;++i){
		g[i]=(w[i]>=mid);
		if(g[i]==g[i-1]){
			if(abs(i-n)<abs(flag-n))flag=i;
			if(abs(i-1-n)<abs(flag-n))flag=i;
		}
	}
	if(flag<=0){
		if(g[1]==0)return 0;
		else return 1;
	}
	if(g[flag]==1)return 1;
	else return 0;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();
	g[n+n]=2;
	for(int i=1;i<n+n;++i)w[i]=read();
	int l=0,r=n+n,ans;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
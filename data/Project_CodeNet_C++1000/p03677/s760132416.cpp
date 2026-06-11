#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define oo 100000000000000
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){
	int x=0,f=0;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	return f?-x:x;
}
int n,m,a[N];
ll sum[N],ans,all;
int main(){
	n=read();m=read();
	For(i,1,n) a[i]=read();
	For(i,2,n){
		int l=a[i-1],r=a[i];
		if(r<l) r+=m;
		all+=r-l;
		if(r-l>1){
			sum[l+2]++;
			sum[r+1]-=r-l;
			sum[r+2]+=r-l-1;
		}
	}
	For(i,1,m<<1) sum[i]+=sum[i-1];
	For(i,1,m<<1) sum[i]+=sum[i-1];
	For(i,1,m) ans=max(ans,sum[i]+sum[i+m]);
	cout<<all-ans;
	return 0;
}
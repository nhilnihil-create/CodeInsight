#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 200010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],b[N],ans,l,r;
inline bool check(int x){
	int l=n-1,r=n+1;
	for(int i=1;i<=2*n-1;i++){
		a[i]=(b[i]>=x);	
	}
	while(l>=1){
		if(a[l]==a[l+1]){
			return a[l];
		}
		if(a[r]==a[r-1]){
			return a[r];
		}
		--l,++r;
	}
	return a[1];
}
int main(){
//	freopen("pyramid.in","r",stdin);
//	freopen("pyramid.out","w",stdout);
	n=read();
	for(int i=1;i<=2*n-1;i++){
		b[i]=read();
	}
	l=1,r=1e8;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid;
		}
	}	
	printf("%d\n",ans);
	return 0;
}

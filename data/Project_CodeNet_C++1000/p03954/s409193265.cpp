#include<bits/stdc++.h>
#define LL long long 
using namespace std;

inline int read(){
	int res=0,f=1;char ch=' ';
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res*f;
}
const int N=200005;
int n;
int a[N];
inline bool big(int i,int j,int mid){
	return a[i]>mid&&a[j]>mid;
}
inline bool small(int i,int j,int mid){
	return a[i]<=mid&&a[j]<=mid;
}
inline bool check(int mid){
	for(register int i=0;i<n-1;i++){
		if(big(n+i,n+i+1,mid)||big(n-i,n-i-1,mid)) return false;
		if(small(n+i,n+i+1,mid)||small(n-i,n-i-1,mid)) return true;
	}
	return small(1,1,mid);
}
int main(){
	n=read();
	for(register int i=1;i<=n*2-1;i++) a[i]=read();
	int l=0,r=2*n-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			r=mid-1;ans=mid;
		}
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
/*
7
1 2
3 1
3 4
5 4
4 7
6 2
3
1
2
3
*/
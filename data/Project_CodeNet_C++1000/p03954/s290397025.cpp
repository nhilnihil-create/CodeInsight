#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return f*ans;
}
const int MAXN=200001;
int n,a[MAXN],b[MAXN],l,r,maxn;
bool check(int val){
	for(int i=1;i<=2*n-1;i++) b[i]=(a[i]>=val);
	for(int i=0;i<n-1;i++){
		if(b[n-i]==b[n-i-1]) return b[n-i];
		if(b[n+i]==b[n+i+1]) return b[n+i];
	}return b[1];
}
int main(){
//	freopen("4.in","r",stdin);
	n=read();
	for(int i=1;i<=2*n-1;i++) a[i]=read();
	l=1,r=2*n-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) l=mid+1,maxn=mid;
		else r=mid-1;
	}printf("%d\n",maxn);
}

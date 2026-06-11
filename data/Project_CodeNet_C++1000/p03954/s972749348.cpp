#include <bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define re register
#define N 501000
#define pb push_back
using namespace std;

struct edge{
	int dis,to,next;
}e[N<<1];
inline int read(){
	int x=0,w=0;char ch=getchar();
	while (!isdigit(ch))w|=ch=='-',ch=getchar();
	while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
	return w?-x:x;
}
int n,ans,a[N],b[N];
inline bool check(int x){
	for (int i=1;i<=(n<<1)-1;++i)b[i]=a[i]>=x;
	for (int i=1;i<n;++i){
		if (b[n+i-1]==b[n+i])return b[n+i];
		if (b[n-i+1]==b[n-i])return b[n-i];
	}
	return b[1];
}
signed main(){
	n=read();
	for (int i=1;i<=(n<<1)-1;++i)a[i]=read();
	int l=1,r=(n<<1)-1;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}

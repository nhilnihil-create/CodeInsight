//Code by Enderturtle
#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define repe(i,a) for(register int i=head[a];i;i=e[i].nxt)
#define il inline
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
typedef long long ll;
using namespace std;
il void filejudge(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
il int read(){
	int x=0;bool f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=0;ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return f?x:-x;
}
/*----- head end -----*/
const int N=100100;
int n,a[N<<1],ans;
il bool check(int mid){
	rep(i,0,n-2){
		if(((a[n+i]<=mid) && (a[n+i+1]<=mid)) || ((a[n-i]<=mid) && (a[n-i-1]<=mid))) return 1;
		if(((a[n+i]>mid) && (a[n+i+1]>mid)) || ((a[n-i]>mid) && (a[n-i-1]>mid))) return 0;
	}
	return (a[1]<=mid);
}
int main(){
	n=read();rep(i,1,2*n-1) a[i]=read();
	int l=1,r=2*n-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
	return 0;
}
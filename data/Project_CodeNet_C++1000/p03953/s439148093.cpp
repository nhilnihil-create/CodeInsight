#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
#define ls lc,l,mid
#define rs rc,mid+1,r
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1000005;
int p[N],vis[N],q[N];
ll a[N],ans[N],s,k;
int n,m,len,x;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		a[i]-=s,s+=a[i];
		p[i]=i;
	}
	read(m),read(k);
	rep(i,1,m){
		read(x);
		swap(p[x],p[x+1]);
	}
	rep(i,1,n){
		if(vis[i]) continue; len=0;
		for(int j=i;!vis[j];j=p[j]) q[len++]=j,vis[j]=1;
		REP(j,len) ans[q[j]]=a[q[(j+k)%len]];
	}
	rep(i,1,n){
		ans[i]+=ans[i-1];
		printf("%lld.0\n",ans[i]);
	}
	return 0;
}
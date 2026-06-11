#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
int n,K,a[N],b[N],d[N],q[N];
int main(){
	n=rd(),K=rd();
	rep(i,1,n)a[i]=rd();
	int ans=0;
	if(a[1]!=1)ans++,a[1]=1;
	if(K==1){
		rep(i,2,n){
			ans+=(a[i]!=1);
		}
		cout<<ans<<endl;
		return 0;
	}
	rep(i,2,n){
		d[a[i]]++;
	}
	int h=0,t=0;
	rep(i,2,n)if(!d[i]){
		q[t++]=i;
	}
	while(h<t){
		int x=q[h++];
		if(x==1)continue;
		b[x]=max(b[x],1);
		if(b[x]>=K)++ans;
		else b[a[x]]=max(b[a[x]],b[x]+1);
		if(!--d[a[x]]&&a[a[x]]!=1&&a[x]!=1){
			q[t++]=a[x];
		}
	}
	cout<<ans<<endl;
}
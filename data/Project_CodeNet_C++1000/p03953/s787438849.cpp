#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)
inline ll rd() {
    ll x;char c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
 
const int N=100000+19;
 
ll x[N],tmp;
int P[60][N],Q[N];
int A[N];
int n,m,u;
ll K;
 
int main(){
	n=rd();
	rep(i,1,n)i[x]=rd();
	m=rd(),K=rd();
	rep(i,1,n-1){
		i[0[P]]=i;
		i[Q]=i;
	}
	rep(i,1,m){
		u=rd();
		swap(u[0[P]],P[0][u-1]);
	}
	rep(t,1,59){
		rep(i,1,n-1) i[t[P]]=P[t-1][P[t-1][i]];
	}
	rep(t,0,59) if (K>>t&1){
		rep(i,1,n-1) i[Q]=i[Q][t[P]];
	}
	tmp=1[x];
	printf("%lld\n",tmp);
	rep(i,1,n-1){
		tmp+=x[Q[i]+1]-i[Q][x];
		printf("%lld\n",tmp);
		//printf("%.10lf\n",tmp);
	}
}
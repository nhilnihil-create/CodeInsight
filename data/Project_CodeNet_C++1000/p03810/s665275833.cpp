#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=(TT=but)+fread(but,1,1<<15,stdin),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e5+11;
int n,A[N];
const char AN[2][123]={"First","Second"};
int main(){
	n=rd();
	rep(i,1,n)A[i]=rd();
	for(int ttt=0;;ttt^=1){
		bool flag=0;
		rep(i,1,n)if(A[i]==1)flag=1;
		if(flag){
			ll tot=0;
			rep(i,1,n)tot+=A[i]-1;
			return puts(tot%2?AN[ttt]:AN[ttt^1]),0;
		}else{
			int t=0;
			rep(i,1,n)t+=A[i]%2;
			if((n-t)%2)return puts(AN[ttt]),0;
			else if((n-t)%2==0&&t>=2)return puts(AN[ttt^1]),0;
			int d=0;
			rep(i,1,n)if(A[i]%2){
				A[i]--;break;
			}
			rep(i,1,n)d=__gcd(d,A[i]);
			rep(i,1,n)A[i]/=d;
		}
	}
}
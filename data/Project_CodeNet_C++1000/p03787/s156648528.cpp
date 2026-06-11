#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
const LL MOD = (LL)1e9+7;
const int SIZE = 2e5+5;
const LL INF = 1LL<<29;
const double eps = 1e-4;
const double PI=3.1415926535897932;

vector<int> adj[100009];
int c[100009];
int isbt;

void dfs(int x){
	for(int i:adj[x]){
		if(c[i]==-1){
			c[i]=c[x]^1;
			dfs(i);
		}
		else{
			if((c[i]^c[x])!=1)isbt=0;
		}
	}
}

int main(){
	DRII(n,m);
	REP(i,m){
		DRII(a,b);a--;b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	MS1(c);
	LL v1=0,v2=0,v3=0;
	REP(i,n){
		if(c[i]!=-1)continue;
		if(SZ(adj[i])==0){c[i]=0,v1++;}
		else{
			isbt=1;c[i]=0;
			dfs(i);
			if(isbt)v2++;
			else v3++;
		}
	}
	//printf("%lld %lld %lld\n",v1,v2,v3);
	printf("%lld",2LL*v2*v2+v1*v1+v3*v3+2LL*v2*v3+2LL*v1*(n-v1));
}

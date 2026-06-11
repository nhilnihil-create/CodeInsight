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
const LL MOD = 1e9+7;
const int SIZE = 2e5+5;
const LL INF = 1LL<<60;
const double eps = 1e-4;
const double PI=3.1415926535897932;

int x[100009];

int main(){
	DRI(n);
	REP(i,n){
		RI(x[i]);
		if(i==0){x[i]=1;continue;}
	}
	LL ans=1;
	set<int> s;
	int ci=-1;
	REP(i,n){//things taken away
		while(ci+1<n){
			if(SZ(s)>=2){
				int v1=*(prev(s.end(),1));
				int v2=*(prev(s.end(),2));
				if(v2==v1-1){
					s.erase(v1);break;
				}
			}
			if(SZ(s)>=1)s.insert(min(x[ci+1],*s.rbegin()+2));
			else s.insert(1);
			ci++;
		}
		ans=(ans*(ci+1-i))%MOD;
	}
	printf("%lld",ans);
}

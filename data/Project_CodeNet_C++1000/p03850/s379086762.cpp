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
#define VPII vector<pair<int,int> >
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
const LL MOD = 1e9+7;
const int SIZE = 1e6+5;
const LL INF = 1LL<<58;
const double eps = 1e-13;

int v[100009];
bool o[100009];
LL l[100009];
LL r[100009];

int main(){
	DRI(n);
	RI(v[0]);
	REPP(i,1,n){
		char c;scanf(" %c",&c);
		o[i]=(c=='+');
		RI(v[i]);
	}
	LL sum=0;
	REP(i,n){
		sum+=v[i];
	}
	REPP(i,1,n){
		if(!o[i]){
			l[i]=l[i-1]+v[i]*2;
		}
		else l[i]=l[i-1];
	}
	REPP(i,1,n){
		if(!o[i]){
			r[i]=2*v[i];
			for(int j=i+1;j<n;j++){
				if(!o[j])break;
				r[i]+=2*v[j];
			}
		}
	}
	//REP(i,n)printf("%lld ",l[i]);puts("");
	//REP(i,n)printf("%lld ",r[i]);puts("");
	LL cmax=-INF;
	REPP(i,1,n){
		if(!o[i]){
			cmax=max(cmax,sum-l[i-1]-r[i]);
		}
	}
	if(cmax==-INF){
		cmax=sum;
	}
	printf("%lld",cmax);
}

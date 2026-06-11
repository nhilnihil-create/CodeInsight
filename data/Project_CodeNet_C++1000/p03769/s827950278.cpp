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
const LL INF = 1LL<<60;
const double eps = 1e-4;
const double PI=3.1415926535897932;
const LL MULT = 1e7;

deque<int> dp(LL x){
	if(x==1)return deque<int>();
	if(x%2){
		deque<int> h=dp(x-1);
		int mv=0;
		for(int i:h){mv=max(mv,i);}
		h.push_front(mv+1);
		return h;
	}
	else{
		deque<int> h=dp(x/2);
		int mv=0;
		for(int i:h){mv=max(mv,i);}
		h.PB(mv+1);
		return h;
	}
}

int main(){
	LL x;cin>> x;
	deque<int> v=dp(x+1);
	int mv=0;
	for(int i:v){mv=max(mv,i);}
	REP(i,mv){
		v.PB(i+1);
	}
	printf("%d\n",SZ(v));
	for(int i:v)printf("%d ",i);
}

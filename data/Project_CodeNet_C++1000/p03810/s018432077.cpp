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
const int SIZE = 1e6+5;
const LL INF = 1LL<<60;
const double eps = 1e-4;
const double PI=3.1415926535897932;

int v[100009];

int main(){
	int e=0,o=0;
	DRI(n);
	REP(i,n){
		RI(v[i]);
		if(v[i]%2)o++;
		else e++;
	}
	if(n==1){
		if(v[0]%2)printf("Second");
		else printf("First");
		return 0;
	}
	REPP(i,1,n){
		if(((v[0]%2==0)&&(v[i]%2))||v[i]==1)swap(v[0],v[i]);
	}
	if((v[0]==1||o!=1)&&(o%2==n%2)){
		printf("Second");return 0;
	}
	if((v[0]==1||o!=1)&&(o%2!=n%2)){
		printf("First");return 0;
	}
	bool isp1=1;
	while(1){
		isp1^=1;
		v[0]--;
		int gc=v[0];
		REPP(i,1,n){
			gc=__gcd(gc,v[i]);
		}
		REP(i,n)v[i]/=gc;
		int ended=1;
		REP(i,n){
			ended&=(v[i]==1);
		}
		if(ended){
			if(isp1)printf("Second");
			else printf("First");
			return 0;
		}
		e=0,o=0;
		REP(i,n){
			if(v[i]%2)o++;else e++;
		}
		REPP(i,1,n){
			if(((v[0]%2==0)&&(v[i]%2))||v[i]==1)swap(v[0],v[i]);
		}
		if((v[0]==1||o!=1)&&(o%2==n%2)){
			if(isp1)printf("Second");
			else printf("First");
			return 0;
		}
		if((v[0]==1||o!=1)&&(o%2!=n%2)){
			if(isp1)printf("First");
			else printf("Second");
			return 0;
		}
	}
}

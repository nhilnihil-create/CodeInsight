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
const LL INF = 1LL<<60;
const double eps = 1e-13;

bool myquery(LL x){
	printf("? %lld\n",x);fflush(stdout);
	char c;scanf(" %c",&c);
	return c=='Y';
}

LL p[10];

int main(){
	p[0]=1;
	REPP(i,1,16)p[i]=p[i-1]*10;
	LL cur=0;
	REP(d,10){
		LL st=0,en=9;
		while(st<en){
			LL mi=(st+en+1)/2;
			LL qi=(cur*10+mi);
			while(qi<=1000000000)qi*=10;
			if(myquery(qi))en=mi-1;
			else st=mi;
		}
		cur=cur*10+st;
	}
	cur++;
	while(cur<=1000000000)cur*=10;
	while(cur/10){
		if(((cur/10)%10)!=9){
			if(!myquery(cur/10+1)){
				printf("! %lld\n",cur);return 0;
			}
		}
		else{
			if(myquery((cur/10-1)*10)){
				printf("! %lld\n",cur);return 0;
			}
		}
		cur/=10;
	}
	printf("! %lld\n",cur);return 0;
}

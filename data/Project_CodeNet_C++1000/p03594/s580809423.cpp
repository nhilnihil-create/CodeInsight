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
typedef pair<double,double> PDD;
const LL MOD = 1e9+7;
const int INF = 1<<30;
int MAXN = 1e5+2;
const double eps = 1e-13;

int r,c,d,h;
char ans[1009][1009];
char col[]="RYGB";

void cen(int x,int y,int v){
	for(int i=x-h;i<=x+h;i++){
		for(int j=y-h;j<=y+h;j++){
			if(i<0||j<0||i>=r||j>=c)continue;
			int dist1=abs(i-x)+abs(j-y);
			int dist3=abs(i-x)+abs(j-y-1);
			if(min(dist1,dist3)>h)continue;
			//printf("yay");
			ans[i][j]=col[v];
		}
	}
}

int main(){
	RIII(r,c,d);
	if(d%2){
		REP(i,r){
			REP(j,c){
				ans[i][j]=col[(i+j)%4];
			}
		}
	}
	else if(d==2){
		REP(i,r){
			REP(j,c){
				ans[i][j]=col[(2*i+(i+j)/2)%4];
			}
		}
	}
	else{
		h=d/2;
		int mm=1000/max(h,1);
		for(int ix=-mm;ix<=mm;ix++){
			for(int iy=-mm;iy<=mm;iy++){
				int cx=ix*(1)+iy*(h);
				int cy=ix*(2*h-1)+iy*(-h);
				cen(cx,cy,(((ix+mm)%2))^(2*iy+mm)%4);
			}
		}
	}
	REP(i,r){
		REP(j,c){
			printf("%c",ans[i][j]);
		}puts("");
	}
}

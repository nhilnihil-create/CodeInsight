#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORq(i, m, n) for(int i = (m);i <= (n);++i)
#define SCD(n) scanf("%d",&n)
#define SCD2(m,n) scanf("%d%d",&m,&n)
#define SCD3(m,n,k) scanf("%d%d%d",&m,&n,&k)
#define PB push_back
#define MP make_pair
#define ARSCD(A,N) REP(i,N){SCD(A[i]);}
#define ARSCD1(A,N) FORq(i,1,N){SCD(A[i]);}
#define PRINTD(n) printf("%d\n",n)
#define PRINTLLD(n) printf("%lld\n",n)
#define DEBUG printf("%s\n","debug")
#define fst first
#define snd second
#define IN(x,S) (S.count(x) != 0)
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef long long ll;
//////////////////////////////////////////////////////
int main(){
	int N,T;
	SCD2(N,T);
	
	static int A[100002];
	
	ARSCD1(A,N);
	
	int buy = A[1];
	int profit = 0;
	int Tc = T/2;
	
	FORq(i,2,N){
		if (buy < A[i]){
			profit = max(profit,(A[i] - buy));
		}else{
			buy = A[i];
		}
	}
	
	set<int> flg;
	
	buy = A[1];
	int buyin = 1;
	
	FORq(i,2,N){
		if (buy < A[i]){
			if ((A[i] - buy) == profit){
				flg.insert(i);
				flg.insert(buyin);
			}
		}else{
			buy = A[i];
			buyin = i;
		}
	}
	
	PRINTD(flg.size() / 2);

	
    
   	return 0;
}
#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)
	
using namespace std;
const int MAX_N=300;
int N;
ll A[MAX_N][MAX_N];
int main(){
	cin>>N;
	REP(i,N){REP(j,N){
		cin>>A[i][j];
	}}
	bool flg=true;
	REP(u,N){
		REP(v,N){
			REP(w,N){
				if (A[u][v]>A[u][w]+A[w][v]){
					flg=false;
				}
			}
		}
	}
	if (flg){
		ll sm=0;
		REP(u,N){
			FOR(v,u+1,N){
				bool f=true;
				REP(w,N){
					if (w==u || w==v)continue;
					if (A[u][v]==A[u][w]+A[w][v]){
						f=false;
					}
				}
				if (f){
					sm+=A[u][v];
				}
			}
		}
		cout<<sm<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}
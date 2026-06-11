#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,a) FOR(i,0,a)

const int MAX_N=1e5;

int N,A[MAX_N];

int gcd(int a,int b){
	if (b==0){
		return a;
	}
	return gcd(b,a%b);
}

bool solve(){
	bool win=true;
	while(1){
		int os=0,es=0;
		REP(i,N){
			if (A[i]%2==1){
				os++;
			}else{
				es++;
			}
		}
		if (es%2==1){
			break;
		}
		if (os==1){
			REP(i,N){
				if (A[i]%2==1){
					if (A[i]==1){
						win=!win;
						return win;
					}else{
						A[i]--;
					}
				}
			}
			int g=A[0];
			FOR(i,1,N){
				g=gcd(g,A[i]);
			}
			REP(i,N){
				A[i]/=g;
			}
			win=!win;
		}else{
			win=!win;
			break;
		}
	}
	return win;
}

int main(){
	cin>>N;
	REP(i,N){
		cin>>A[i];
	}
	if (solve()){
		cout<<"First"<<endl;
	}else{
		cout<<"Second"<<endl;
	}
	return 0;
}

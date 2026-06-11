#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int main(){
	ll N;
	cin >> N;
	ll A[N][N];
	ll B[N][N];
	REP(i, N) REP(j, N) cin >> A[i][j];
	REP(i, N) REP(j, N) B[i][j] = A[i][j];
	bool flag = true;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			for (int k=0;k<N;k++){
				if (i!=k && j!=k){
					if(A[i][j] > A[i][k]+A[j][k]){
						flag = false;
					}
					if(A[i][j] == A[i][k] + A[j][k]){
						B[i][j] = 0;
					}
				}
			}
		}
	}
	ll res = 0;
	for(int i=0;i<N;i++){
		for (int j=i+1;j<N;j++){
			res += B[i][j];
		}
	}
	if(!flag){
		cout << -1 << endl;
	}else{
		cout << res << endl;
	}
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//container util
#define SORT(c) sort((c).begin(),(c).end())

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

const int INF = 1e9;

int main(void){

	int N, M, K; cin >> N >> M >> K;

	string ans = "No";
	REP(x,M+1){
		REP(y,N+1){
			if(x*N + y*M - 2*x*y == K) ans = "Yes";
		}
	}

	cout << ans << endl;

	return 0;

}

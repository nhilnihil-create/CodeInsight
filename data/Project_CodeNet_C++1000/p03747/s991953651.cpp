#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int i = 0;i < (n);i++)
#define FOR(i, a, b) for(int i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-6;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

const int64 mod = 1e9+7;

int main(void){
	int64 N, L, T;
	cin >> N >> L >> T;
	vector<int64> X(N), W(N);
	REP(i, N) cin >> X[i] >> W[i];
	int64 cnt = 0;
	REP(i, N){
		if(W[i] == 1){
			cnt += (X[i]+T-1)/L;
			X[i] = (X[i]+T)%L;
		}else{
			cnt -= ((L-X[i])+T-1)/L;
			X[i] = (X[i]-T%L+L)%L;
		}
	}
	cnt = (cnt%N+N)%N;
	sort(all(X));
	REP(i, N){
		cout << X[(i+cnt)%N] << endl;
	}
}
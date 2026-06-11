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

const int64 mod = 1777777777;
using PIC = pair<int32, char>;

int main(void){
	int32 n, m;
	vector<int64> a;
	vector<int64> sum;
	vector<PLL> v;
	cin >> n >> m;
	sum.resize(3*m+2);
	a.resize(n);
	REP(i, n){
		cin >> a[i];
	}
	REP(i, n-1){
		if(a[i] > a[i+1]){
			v.emplace_back(a[i]+1, a[i+1]+m);
			v.emplace_back(a[i]+m+1, a[i+1]+2*m);
			sum[a[i]+1]++;
			sum[a[i+1]+m]--;
			sum[a[i]+m+1]++;
			sum[a[i+1]+2*m]--;
		}else{
			v.emplace_back(a[i]+1, a[i+1]);
			sum[a[i]+1]++; sum[a[i+1]]--;
			v.emplace_back(a[i]+m+1, a[i+1]+m);
			sum[a[i]+m+1]++; sum[a[i+1]+m]--;
			v.emplace_back(a[i]+2*m+1, a[i+1]+2*m);
			sum[a[i]+2*m+1]++; sum[a[i+1]+2*m]--;
		}
	}
	REP(i, sum.size()-1) sum[i+1] += sum[i];
	REP(i, v.size()) sum[v[i].sc] -= v[i].sc-v[i].fs;
	REP(i, sum.size()-1) sum[i+1] += sum[i];
	int64 res = 0;
	REP(i, sum.size()) res = min(res, -sum[i]);
	REP(i, n-1){
		if(a[i] < a[i+1]) res += a[i+1]-a[i];
		else res += a[i+1]+m-a[i];
	}
	cout << res << endl;
}
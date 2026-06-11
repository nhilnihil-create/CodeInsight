#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];

ll mod(double a, double b){
	return a - floor(a / b) * b;
}

int main(){
	IOS;
	ll n, m;
	cin >> n >> m;
	vec<ll> x(n), y(m);
	REP(i, n)cin >> x[i];
	REP(i, m)cin >> y[i];
	ll sumx = 0;
	ll sumy = 0;
	REP(i, n){
		sumx -= (n - i - 1) * x[i];
		sumx = mod(sumx,MOD);
		sumx += i * x[i];
		sumx = mod(sumx,MOD);
	}
	REP(i, m){
		sumy -= (m - i - 1) * y[i];
		sumy = mod(sumy,MOD);
		sumy += i * y[i];
		sumy = mod(sumy,MOD);
	}
	dump((sumx * sumy) % MOD);
}
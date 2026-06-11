// tsukasa_diary's programing contest code template
#include <bits/stdc++.h>
using namespace std;
#define TSUKASA_DIARY_S_TEMPLATE
// define
#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
#define minit(a,b) memset(a,b,sizeof(a))
#define size_of(a) int((a).size())
#define cauto const auto
// typedef
typedef long long lint;
typedef double Double;
typedef pair< int, int > pii;
template< typename T > using Vec = vector< T >;
template< typename T > using Matrix = Vec< Vec< T > >;
template< typename T > using USet = unordered_set< T >;
template< typename T, class C > using MyUSet = unordered_set< T, C >;
template< typename T, typename F > using UMap = unordered_map< T, F >;
template< typename T, typename F, class C > using MyUMap = unordered_map< T, F, C >;
// hash
class PiiHash { public: size_t operator () (const pii& p) const { return (p.first << 16) | p.second; } };
// popcount
inline int POPCNT(int x) { return __builtin_popcount(x); }
inline int POPCNT(lint x) { return __builtin_popcount(x); }
// inf
const int iINF = 1L << 30;
const lint lINF = 1LL << 60;
// eps
const Double EPS = 1e-9;
const Double PI = acos(-1);
// inrange
template< typename T >
inline bool in_range(T v, T mi, T mx) { return mi <= v && v < mx; }
template< typename T >
inline bool in_range(T x, T y, T W, T H) { return in_range(x,0,W) && in_range(y,0,H); }
// neighbor clockwise
const int DX[4] = {0,1,0,-1}, DY[4] = {-1,0,1,0};
const int DX_[8] = {0,1,1,1,0,-1,-1,-1}, DY_[8] = {-1,-1,0,1,1,1,0,-1};
// variable update
template< typename T > inline void modAdd(T& a, T b, T mod) { a = (a + b) % mod; }
template< typename T > inline void modMul(T& a, T b, T mod) { a = (a * b) % mod; }
template< typename T > inline void minUpdate(T& a, T b) { a = min(a, b); }
template< typename T > inline void maxUpdate(T& a, T b) { a = max(a, b); }
// converter
template< typename F, typename T >
inline void convert(F& from, T& to) {
	stringstream ss;
	ss << from; ss >> to;
}


int N, M, X[100010];
const int MAX_X = 100000;

void solve() {
	Vec< int > cnt(MAX_X + 1, 0);
	for_(i,0,N) cnt[X[i]]++;
	
	Vec< priority_queue< int, Vec< int >, greater< int > > > vque(M);
	//Vec< int > odd_cnt(M, 0);
	for_rev(x,MAX_X,1) {
		if (cnt[x] > 0) {
			if (cnt[x] % 2) {
				vque[x % M].push(1);
				vque[x % M].push(cnt[x] - 1);
				//++odd_cnt[x % M];
			} else {
				vque[x % M].push(cnt[x]);				
			}
		}
	}
	
	int ans = 0;
	
	for_(x,0,M) {
		int a = x, b = (M - a) % M;
		//cerr << a << " " << b << endl;
		if (a == b) {
			/*
			ans += odd_cnt[a] / 2; odd_cnt[a] %= 2;
			for_(i,0,odd_cnt[a]) vque[a].push(1);
			odd_cnt[a] = 0;
			*/
			while (vque[a].size() > 1) {
				int t = vque[a].top(); vque[a].pop();
				int s = vque[a].top(); vque[a].pop();
				ans += t;
				if (s - t > 0) vque[a].push(s - t);
			}
		} else {
			/*
			int add = min(odd_cnt[a], odd_cnt[b]);
			ans += add;
			odd_cnt[a] -= add;
			odd_cnt[b] -= add;
			for_(i,0,odd_cnt[a]) vque[a].push(1);
			for_(i,0,odd_cnt[b]) vque[a].push(1);
			odd_cnt[a] = odd_cnt[b] = 0;
			*/
			while (!vque[a].empty() && !vque[b].empty()) {
				int ta = vque[a].top(); vque[a].pop();
				int tb = vque[b].top(); vque[b].pop();
				int sub = min(ta, tb);
				ans += sub;
				if (ta - sub > 0) vque[a].push(ta - sub);
				if (tb - sub > 0) vque[b].push(tb - sub);
			}
		}
		//cerr << "#" << ans << endl;
	}
	
	for_(x,0,M) {
		while (!vque[x].empty()) {
			ans += vque[x].top() / 2;
			vque[x].pop();
		}
	}
	
	cout << ans << endl;
}

int main() {
	cin >> N >> M;
	for_(i,0,N) cin >> X[i];
	solve();
}





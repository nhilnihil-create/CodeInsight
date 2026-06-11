//------------------------------>> tsukasa_diary's template <<------------------------------//
#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define for_rev(i,a,b) for(int i=(a);i>=(b);--i)
#define allof(a) (a).begin(),(a).end()
#define minit(a,b) memset(a,b,sizeof(a))

using lint = long long;
using pii = pair< int, int >;

template< typename T > using Vec = vector< T >;

template< typename T > bool in_range(T x, T lb, T ub) { return lb <= x && x < ub; }
template< typename T > bool in_range(T x, T y, T lb, T ub) { return in_range(x, lb, ub) && in_range(y, lb, ub); }

template< typename T > void modAdd(T& a, T b, T mod) { a = (a + b + mod) % mod; }
template< typename T > void modMul(T& a, T b, T mod) { a = (a * b) % mod; }
template< typename T > void minUpdate(T& a, T b) { a = min(a, b); }
template< typename T > void maxUpdate(T& a, T b) { a = max(a, b); }

int bitCount(int x) { return __builtin_popcount(x); }
int bitCount(lint x) { return __builtin_popcountll(x); }

const int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
const int Dx[8] = {0,1,1,1,0,-1,-1,-1}, Dy[8] = {-1,-1,0,1,1,1,0,-1};
const double EPS = 1e-9;
const double PI = acos(-1);

//--------------8---------------->> coding space <<-----------------8-------------//

int main() {
	int W, H;
	cin >> W >> H;
	
	Vec< lint > p(W+1), q(H+1);
	for_(i,0,W) cin >> p[i];
	for_(i,0,H) cin >> q[i];
	
	p[W] = q[H] = (lint)1e9;
	
	sort(allof(p));
	sort(allof(q));
	
	int i = 0, j = 0;
	lint ans = 0;
	while (i < W || j < H) {
		if (p[i] < q[j]) {
			ans += p[i] * (H+1-j);
			++i;
		} else {
			ans += q[j] * (W+1-i);
			++j;
		}
	}
	cout << ans << endl;
}
//--------------8---------------->> coding space <<-----------------8-------------//

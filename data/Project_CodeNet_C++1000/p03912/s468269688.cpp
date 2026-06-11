#include <cstdio>
#include <cmath>

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define inc( i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define dec( i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

template<typename T> void swap(T & x, T & y) { T t = x; x = y; y = t; return; }
template<typename T> T abs(T x) { return (0 <= x ? x : -x); }
template<typename T> T max(T a, T b) { return (b <= a ? a : b); }
template<typename T> T min(T a, T b) { return (a <= b ? a : b); }
template<typename T> bool setmin(T & a, T b) { if(a <= b) { return false; } else { a = b; return true; } }
template<typename T> bool setmax(T & a, T b) { if(b <= a) { return false; } else { a = b; return true; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

int n, m, x[100000];
int num[100001], sum[100000], odd[100000];

int main() {
	scanf("%d%d", &n, &m);
	inc(i, n) { scanf("%d", &x[i]); }
	
	inc(i, n) { num[ x[i] ]++; }
	
	incII(i, 1, 100000) {
		sum[i % m] += num[i];
		odd[i % m] += num[i] % 2;
	}
	
	int ans = 0;
	incII(i, 0, (m / 2)) {
		int mi = (odd[i] < odd[(m - i) % m] ? i : (m - i) % m);
		int ma = (odd[i] < odd[(m - i) % m] ? (m - i) % m : i);
		
		if(mi == ma) { ans += sum[mi] / 2; continue; }
		
		if(sum[mi] >= odd[ma]) { ans += (sum[mi] + sum[ma]) / 2; }
		else { ans += sum[mi] + (sum[ma] - odd[ma]) / 2; }
		
		// printf("<%d, %d>: ans = %d\n", mi, ma, ans);
	}
	
	printf("%d\n", ans);
	
	return 0;
}

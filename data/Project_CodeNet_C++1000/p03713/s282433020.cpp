#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}


signed main(void) {
	int h, w;
	cin >> h >> w;
	if (h % 3 == 0 || w % 3 == 0) {
		print(0);
		return 0;
	}
	int ret = INF;
	rep1(i, h) {
		int s1 = i * w;
		int s2 = (h - i)*(w / 2);
		int s3 = (h - i)*w - s2;
		int s4 = (h - i) / 2 * w;
		int s5 = (h - i)*w - s4;
		ret = min(ret, max({ s1, s2, s3 }) - min({ s1, s2, s3 }));
		ret = min(ret, max({ s1, s4, s5 }) - min({ s1, s4, s5 }));
	}
	swap(h, w);
	rep1(i, h) {
		int s1 = i * w;
		int s2 = (h - i)*(w / 2);
		int s3 = (h - i)*w - s2;
		int s4 = (h - i) / 2 * w;
		int s5 = (h - i)*w - s4;
		ret = min(ret, max({ s1, s2, s3 }) - min({ s1, s2, s3 }));
		ret = min(ret, max({ s1, s4, s5 }) - min({ s1, s4, s5 }));
	}
	print(ret);
}
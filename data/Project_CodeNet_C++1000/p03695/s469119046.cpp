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
	int n;
	cin >> n;
	vector<int>a(9,0);
	rep(i, n) {
		int tmp;
		cin >> tmp;
		if (1 <= tmp && tmp <= 399)a[0]++;
		else if (400 <= tmp && tmp <= 799)a[1]++;
		else if (800 <= tmp && tmp <= 1199)a[2]++;
		else if (1200 <= tmp && tmp <= 1599)a[3]++;
		else if (1600 <= tmp && tmp <= 1999)a[4]++;
		else if (2000 <= tmp && tmp <= 2399)a[5]++;
		else if (2400 <= tmp && tmp <= 2799)a[6]++;
		else if (2800 <= tmp && tmp <= 3199)a[7]++;
		else a[8]++;
	}
	int color = 0;
	int mincolor = 0;
	rep (i, 8) {
		if (a[i] > 0)color++;
	}
	if (color == 0 && a[8] > 0)mincolor = 1;
	else mincolor = color;
	print(mincolor);
	print(color + a[8]);
}
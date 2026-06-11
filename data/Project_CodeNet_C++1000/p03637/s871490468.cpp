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
	vector<int>b(3,0);
	rep(i, n) {
		int a;
		cin >> a;
		if (a % 2 == 1) {
			b[0]++;
		}
		else {
			a /= 2;
			if (a % 2 == 0) {
				b[2]++;
			}
			else b[1]++;
		}
	}
	if (b[1]==0) {
		if (b[0] <= b[2] + 1)print("Yes");
		else print("No");
	}
	else {
		if (b[2] >= b[0])print("Yes");
		else print("No");
	}
}
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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

signed main(void) {
	string s;
	cin >> s;
	int index = s.size();
	while (true) {
		if (index <= 0) {
			print("YES");
			return 0;
		}
		else if (s.substr(index - 5, 5) == "dream" || s.substr(index - 5, 5) == "erase") {
			index -= 5;
		}
		else if (s.substr(index - 6, 6) == "eraser") {
			index -= 6;
		}
		else if (s.substr(index - 7, 7) == "dreamer") {
			index -= 7;
		}
		else {
			print("NO");
			return 0;
		}
	}
}
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
	string aa, bb, cc;
	cin >> aa >> bb >> cc;
	queue<char>a;
	queue<char>b;
	queue<char>c;
	rep(i, aa.size()) {
		a.push(aa[i]);
	}
	rep(i, bb.size()) {
		b.push(bb[i]);
	}
	rep(i, cc.size()) {
		c.push(cc[i]);
	}
	char turn = 'a';
	while (true) {
		if (turn == 'a') {
			if (a.empty()) {
				print("A");
				return 0;
			}
			turn = a.front();
			a.pop();
		}
		else if (turn == 'b') {
			if (b.empty()) {
				print("B");
				return 0;
			}
			turn = b.front();
			b.pop();
		}
		else if (turn == 'c') {
			if (c.empty()) {
				print("C");
				return 0;
			}
			turn = c.front();
			c.pop();
		}
	}
}
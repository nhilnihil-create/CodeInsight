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

int fact(int n) {
	int ans = 1;
	rep(i, n) {
		ans *= n - i;
		ans %= mod;
	}
	return ans %= mod;
}

signed main(void) {
	int n, c, k;
	cin >> n >>c>> k;
	priority_queue<int,vector<int>,greater<int>>t;
	rep(i, n) {
		int tmp;
		cin >> tmp;
		t.push(tmp);
	}
	int ans = 1;
	int passenger = 1;
	int start = t.top();
	t.pop();
	while (!t.empty()) {
		int front = t.top();
		t.pop();
		if ((front - start <= k) &&( passenger < c)) {
			passenger++;
		}
		else {
			ans++;
			start = front;
			passenger = 1;
		}
	}
	println(ans);
}
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
#include<stack>
using namespace std;
#define int long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


signed main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (A & 1 || B & 1 || C & 1) {
		cout << 0 << endl;
		return 0;
	}
	if (A == B && B == C && A == C) {
		cout << -1 << endl;
		return 0;
	}
	int cnt = 0;
	int a = A, b = B, c = C;
	while (1) {
		if (a & 1 || b & 1 || c & 1) {
			cout << cnt << endl;
			return 0;
		}
		int na = b / 2 + c / 2;
		int nb = a / 2 + c / 2;
		int nc = a / 2 + b / 2;
		a = na, b = nb, c = nc;
		cnt++;
	}
}
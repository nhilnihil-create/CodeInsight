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
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
const int INF = 1e10;
const long double PI = (acos(-1));


signed main() {
	string s;
	int K;
	cin >> s >> K;
	int i = 0;
	vector<int>v(s.size());
	rep(i, s.size())v[i] = ('z' - s[i] + 1) % 26;
	rep(i, s.size()) {
		if (K >= v[i]) {
			K -= v[i];
			s[i] = 'a';
		}
	}
	s[s.size() - 1] = s[s.size() - 1] + K % 26;
	rep(i, s.size())cout << s[i];
	cout << endl;
}
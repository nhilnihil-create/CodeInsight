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
//const int MOD = 998244353;
const int INF = 1e10;
const long double PI = (acos(-1));

string dream = "maerd";
string dreamer = "remaerd";
string erase = "esare";
string eraser = "resare";

signed main() {
	int N;
	cin >> N;
	vector<int>A(N);
	set<int>s;
	rep(i, N) {
		cin >> A[i];
		s.insert(A[i]);
	}
	int a = N - s.size();
	int b = (a + 2 - 1) / 2;
	int ans = N - b * 2;
	cout << ans << endl;
}
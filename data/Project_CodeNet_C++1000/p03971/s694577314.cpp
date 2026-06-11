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
	int N, A, B;
	string S;
	cin >> N >> A >> B >> S;
	int a = 0, b = 0, c = 0;
	int sum = 0;
	rep(i, S.size()) {
		if (S[i] == 'a') {
			if (sum < A + B) {
				cout << "Yes" << endl;
				sum++;
			}
			else cout << "No" << endl;
			a++;
		}
		else if (S[i] == 'b') {
			if (sum < A + B && b < B) {
				cout << "Yes" << endl;
				sum++;
			}
			else cout << "No" << endl;
			b++;
		}
		else {
			cout << "No" << endl;
			c++;
		}
	}
}
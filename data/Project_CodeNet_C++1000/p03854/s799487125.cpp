#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main() {
	string S, tmp;
	cin >> S;

	reverse(S.begin(), S.end());
	ll N = S.size(), i = 0;

	while (i != N) {
		if (S[i] == 'e'){
			if (S.substr(i, 5) != "esare") {
				cout << "NO";
				return 0;
			}
			else {
				i += 5;
				continue;
			}
		}
		else if (S[i] == 'm') {
			if (S.substr(i, 5) != "maerd") {
				cout << "NO";
				return 0;
			}
			else {
				i += 5;
				continue;
			}
		}
		else if (S[i] == 'r' && S[i + 1] == 'e') {
			if (S.substr(i, 6) == "resare") {
				i += 6;
				continue;
			}
			else if(S.substr(i, 7) == "remaerd"){
				i += 7;
				continue;
			}
			else {
				cout << "NO";
				return 0;
			}
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}


ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}
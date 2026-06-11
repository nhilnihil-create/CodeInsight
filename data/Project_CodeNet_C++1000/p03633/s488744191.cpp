#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


ll gcd(ll a, ll b) {
	if (a%b==0) return b;
	else return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

int main() {
	int n;
	cin >> n;
	ll A[n];
	rep(i, n) cin >> A[i];

	ll a = A[0];
	for (int i=1; i<n; i++) {
		a = lcm(a, A[i]);
	}
	cout << a << endl;
}
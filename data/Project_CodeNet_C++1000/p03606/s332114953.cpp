#include<iostream>
#include<stack>
#include<string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#define fast(); ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i, n) for(int i= 0; i < n; ++i)
using namespace std;

int gcd(int a, int b) {
	if (a == 0)return b;
	return gcd(b % a, a);
}


int main() {
	fast();

	int n; cin >> n;
	long long res = 0;
	while (n--) {
		int l, r; cin >> l >> r;
		res += abs(r - l) + 1;
	}
	cout << res << endl;
	return 0;
}

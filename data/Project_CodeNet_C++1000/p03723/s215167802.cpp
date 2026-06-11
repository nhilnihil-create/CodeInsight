#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ta, tb, tc;
	int ans = 0;
	while ((a!=b&&b!=c)
		&&(a % 2 == 0 && b % 2 == 0 && c % 2 == 0)) {
		ta = a;
		tb = b;
		tc = c;
		a = (ta + tb) / 2;
		b = (tb + tc) / 2;
		c = (ta + tc) / 2;
		ans++;
	}
	if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1) {
		cout << ans << endl;
	}
	else cout << -1 << endl;
	return 0;
}
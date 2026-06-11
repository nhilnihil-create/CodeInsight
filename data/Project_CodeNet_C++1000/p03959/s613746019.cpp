#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
using namespace std;
long long mod = 1e9 + 7;
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout <<fixed<< setprecision(15);
	int n;
	cin >> n;
	int num[100003];
	int hatena[100003] = { 0 };
	for (int i = 0; i < n; i++) {
		num[i] = INT_MAX;
	}
	int t[100003];
	int a[100003];
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	num[0] = t[0];
	hatena[0] = 1;
	for (int i = 1; i < n; i++) {
		if (t[i] == t[i - 1])num[i] = min(num[i], t[i]);
		else { num[i] = t[i]; hatena[i] = 1; }
	}
	if (num[n - 1] < a[n - 1] || (hatena[n - 1] == 1 && num[n - 1] != a[n - 1])) {
		cout << 0; return 0;
	}
	num[n - 1] = a[n - 1];
	hatena[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] == a[i + 1]) {
			if (hatena[i] == 1 && num[i]>a[i]) {
				cout << 0; return 0;
			}
			else {
				num[i] = min(num[i], a[i]);
			}
		}
		else { 
			if ((hatena[i] == 1 && num[i] != a[i]) || num[i] < a[i]) {
				cout << 0; return 0;
			}
			num[i] = a[i]; hatena[i] = 1; }
	}
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		if (hatena[i] == 0) {
			ans *= num[i];
			ans %= mod;
		}
	}
	cout << ans;
}
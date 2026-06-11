#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	vector<ll> a(3); cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	if (a[0] % 2 == 0 || a[1] % 2 == 0 || a[2] % 2 == 0)
		cout << 0 << endl;
	else
		cout << a[0] * a[1]  << endl;
}
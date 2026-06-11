#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;


int main() {
	ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
	bool flag = false;
	for (int i = 0; i <= N - 1; i++) {
		if (i * C - (N - 1 - i) * D <= abs(B - A) && abs(B - A) <= i * D - (N - 1 - i) * C) {
			flag = true;
			break;
		}
	}
	cout << (flag ? "YES" : "NO") << endl;
}

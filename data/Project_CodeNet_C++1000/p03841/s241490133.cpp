#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
//#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int ng[34578], ans[345678];
signed main() {
	int n, a = 1, cnt = 0; cin >> n;
	vector<vector<int>>test(n, vector<int>(2));
	for (int h = 0; h < n; h++) {
		cin >> test[h][0]; test[h][1] = h + 1; ans[test[h][0]] = h + 1;
		ng[h] = test[h][0];
	}
	sort(ng, ng + n);
	sort(test.begin(), test.end());
	//前
	for (int h = 0; h < n; h++) {
		for (int i = 1; i < test[h][1]; i++) {
			while (a == ng[cnt]) { a++; cnt++; }
			if (a >= test[h][0]) { cout << "No" << endl; return 0; }
			ans[a] = test[h][1]; a++;
		}
	}
	reverse(test.begin(), test.end()); a = n * n; cnt = n - 1;
	//後
	for (int h = 0; h < n; h++) {
		for (int i = 0; i < n - test[h][1]; i++) {
			while (a == ng[cnt]) { a--; cnt--; }
			if (a <= test[h][0]) { cout << "No" << endl; return 0; }
			ans[a] = test[h][1]; a--;
		}
	}
	cout << "Yes" << endl;
	for (int h = 1; h <= n * n; h++) {
		if (h == 1) { cout << ans[h]; }
		else { cout << ' ' << ans[h]; }
	}
	cout << endl;
	return 0;
}
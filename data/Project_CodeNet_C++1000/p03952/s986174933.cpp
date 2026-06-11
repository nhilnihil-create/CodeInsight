#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, x; cin >> N >> x;

	if (x == 1 || x == 2 * N - 1)cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		vector<int> ans(2 * N);
		int cnt = 1;
		for (int i = 1; i <= 2 * N - 1; i++) {
			if (cnt == x - 1)cnt += 3;
			if (N - 1 > i || i > N + 1) {
				ans[i] = cnt;
				cnt++;

			}
			
		}
		
		ans[N] = x;
		ans[N - 1] = x - 1;
		ans[N + 1] = x + 1;
		
		for (int i = 1; i <= 2 * N - 1; i++) {
			cout << ans[i] << endl;
			//cout << ans[i] << " ";
		}

	}

}


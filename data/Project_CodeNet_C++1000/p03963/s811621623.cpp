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

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, K; cin >> N >> K;
	ll ans = K;
	for (int i = 1; i < N;i++) {
		ans *= (K - 1);
	}
	cout << ans << endl;
}


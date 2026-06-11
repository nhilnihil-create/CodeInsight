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
	int N; cin >> N;
	vector<ll> A(N), B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i];

	ll cnt = 0;
	for (int i = N - 1; i >= 0; i--) {
		if ((A[i]+cnt) % B[i] != 0) {
			cnt += B[i] - (A[i] + cnt) % B[i];
		}
	}
	cout << cnt << endl;
}

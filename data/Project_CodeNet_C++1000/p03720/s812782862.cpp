#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
	int N, M, t;
	cin >> N >> M;
	vector<int> a(N, 0);
	rep(i, M) {
		rep(j, 2) {
			cin >> t;
			a[t - 1]++;
		}
	}
	rep(i, N) {
		cout << a[i] << endl;
	}
}



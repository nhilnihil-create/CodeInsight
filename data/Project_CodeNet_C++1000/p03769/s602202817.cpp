#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

int tot = 0;
int Q[1010] = {};
int L = 501, R = 500;

void work(ll x) {
	if (x == 1) {
		return;
	}
	if (x & 1) {
		work(x - 1); 
		Q[--L] = ++tot;
	}
	else {
		work(x >> 1);
		Q[++R] = ++tot;
	}
}

ll N;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	work(N + 1);
	cout << 2 * tot << endl;
	for (int i = L; i <= R; ++i) {
		cout << Q[i] << " ";
	}
	for (int i = 1; i <= tot; ++i) {
		cout << i << " ";
	}
	cout << endl;
	return 0;
}
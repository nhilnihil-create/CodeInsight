#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;
ll cnt[100001];


int main() {
	int n;
	ll k;
	cin >> n >> k;
	rep(i, n) {
		int a;
		int b;
		cin >> a >> b;
		cnt[a] += b;
	}
	for (int x=1; x<=100000; x++) {
		if (k<=cnt[x]) {
			cout << x << endl;
			break;
		}
		k -= cnt[x];
	}
	return 0;
}
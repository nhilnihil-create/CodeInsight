#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < 10000; i++) {
		if (a % 2 || b % 2 || c % 2) {
			cout << i << endl;
			return 0;
		}
		int na = b / 2 + c / 2;
		int nb = a / 2 + c / 2;
		int nc = a / 2 + b / 2;
		a = na;
		b = nb;
		c = nc;
	}
	cout << -1 << endl;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;
typedef long long ll;

int main() {
	int n; cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int l, t;
		cin >> l >> t;
		sum += t - l + 1;
	}
	cout << sum << endl;
}
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
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a.at(i);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] == j+1 && a[j] == i+1) ans++;
		}
	}
	cout << ans << endl;
}
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
#include<iomanip>

using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	vector<int> s(N);
	for (int i = 0; i < N; i++) cin >> s[i];
	int ans = 0;
	for (int i = 0; i < N; i++) ans += s[i];
	if (ans % 10 != 0) {
		cout << ans << endl;
	}
	else {
		sort(s.begin(), s.end());
		for (int i = 0; i < N; i++) {
			if (s[i] % 10 != 0) {
				ans -= s[i];
				cout << ans << endl;
				return 0;
			}
		}
		cout << 0 << endl;
	}
	
}

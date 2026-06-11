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

#define int long long

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	vector<int> f(n);
	{
		vector<int> st;
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.back()] >= a[i]) {
				st.pop_back();
			}
			f[i] = -1;
			if (!st.empty()) f[i] = st.back();
			st.push_back(i);
		}
	}
	vector<int> s(n);
	{
		vector<int> st;
		for (int i = n - 1; i >= 0; i--) {
			while (!st.empty() && a[st.back()] > a[i]) {
				st.pop_back();
			}
			s[i] = n;
			if (!st.empty()) s[i] = st.back();
			st.push_back(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int l = (i - f[i]);
		int r = (s[i] - i);
		// cerr << i << ' ' << l << ' ' << r << endl;
		ans += (a[i] * l * r);
	}
	cout << ans << endl;
}
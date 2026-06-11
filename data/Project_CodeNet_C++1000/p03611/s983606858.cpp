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
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
using ll = long long;


int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	int mx = 0;
	for (auto x : mp) {
		int np = 0;
		int nm = 0;
		if (mp.count(x.first+1)) np = mp[x.first+1];
		if (mp.count(x.first-1)) nm = mp[x.first-1];
		int cnt = x.second + np + nm;
		mx = max(mx, cnt);
	}
	cout << mx << endl;
}
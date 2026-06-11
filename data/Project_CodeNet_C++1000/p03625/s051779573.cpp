#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

int main() {
	long long n, l;
	cin >> n;
	map<long long,long long> m;
	vector<long long> v;
	for (long long i = 0; i < n; i++) {
		cin >> l;
		m[l]++;
		if (m[l] % 2 == 0) v.push_back(l);
	}
	sort(v.begin(), v.end());
	long long s;
	if (v.size() < 2) s = 0;
	else s = v[v.size() - 2] * v[v.size() - 1];
	cout << s << endl;
}
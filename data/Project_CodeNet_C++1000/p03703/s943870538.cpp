#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

#define _USE_MATH_DEFINES

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
#include <math.h>
#include <map>
#include <iomanip>
#include <functional>
#include <string>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}

#define MOD 1000000007

vector<int> fwt(1e6);
int sum(int r) {
	int result = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		result += fwt[r];
	return result;
}

void inc(int i, int delta) {
	for (; i < 1e6; i = (i | (i + 1)))
		fwt[i] += delta;
}


int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long k;
	cin >> n >> k;
	vector<long long > vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	vector<long long> tmp;
	tmp.push_back(0);
	
	long long acc = 0;
	for (int i = 0; i < n; i++)
	{
		acc += vec[i];
		tmp.push_back(acc - k * (i + 1));
	}

	vector<long long> vals = tmp;
	sort(vals.begin(), vals.end());
	vals.erase(unique(vals.begin(), vals.end()), vals.end());
	
	long long ans = 0;
	for (auto x : tmp)
	{
		int i = lower_bound(vals.begin(), vals.end(), x) - vals.begin();
		ans += sum(i);
		inc(i, 1);
	}

	cout << ans;

	return 0;
}

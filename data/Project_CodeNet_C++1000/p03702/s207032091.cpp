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



int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	long long a, b;
	cin >> n >> a >> b;
	vector<long long > vec(n);
	for (int i = 0; i < n; i++)
		cin >> vec[i];

	long long left = 0, right = 1e9 + 1;
	while (left < right)
	{
		long long med = (left + right) / 2;

		vector<long long> tmp = vec;
		for (long long& val : tmp)
		{
			val -= med * b;
		}

		long long need_op = 0;
		for (long long& val : tmp)
		{
			if (val <= 0)
				continue;
			need_op += (val + (a - b) - 1) / (a - b);
		}
		if (need_op <= med)
		{
			right = med;
		}
		else
		{
			left = med + 1;
		}
	}

	cout << left;


	return 0;
}

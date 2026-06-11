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
#include <random>
#include <set>

using namespace std;

template<class T> ostream& operator<<(ostream& os, const vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) os << *i << (i == end(v) - 1 ? "" : " "); return os;
}
template<class T> istream& operator>>(istream& is, vector<T>& v) {
	for (auto i = begin(v); i != end(v); i++) is >> *i; return is;
}

#define MOD 1000000007
#define inf 2000000000



int main() {

#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long x, y;
	cin >> x >> y;

	if (max(x,y) <= 1)
	{
		cout << "Brown";
		return 0;
	}

	if ((x - y + 3000000000000000000LL) % 3 == 0)
	{
		if (x != y)
		{
			cout << "Alice";
		}
		else
		{
			cout << "Brown";
		}
	}
	else
	{
		if ((max(x, y) - min(x, y)) != 1)
		{
			cout << "Alice";
		}
		else
		{
			cout << "Brown";
		}
	}

	return 0;
}

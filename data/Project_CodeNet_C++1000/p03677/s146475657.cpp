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


int main()
{
#if defined(_DEBUG) 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> x(n);
	for (int k = 0; k < n; k++)
		cin >> x[k];

	vector<pair<int, int>> to_right, center;
	long long resp = 0;
	map<int, long long> end_left, bw_start;
	vector<pair<int, int>> bw;


	for (int j = 0; j < n - 1; j++)
	{
		if (x[j] > x[j + 1])
		{
			bw_start[x[j]+1]++;
			bw.push_back({ x[j + 1], x[j] });
			continue;
		}

		end_left[x[j + 1]] += x[j + 1] - x[j];
		to_right.push_back({ x[j], x[j + 1] });
		center.push_back({ x[j] + 1, x[j + 1] });
	}

	sort(center.begin(), center.end(), [&](pair<int, int>& a, pair<int, int>& b) {
		return a.first < b.first;
	});

	vector<long long> sum_right(m + 1);
	for (auto x : to_right)
	{
		sum_right[x.first] += (x.second - x.first);
	}

	for (int i = m; i > 0; i--)
	{
		sum_right[i - 1] += sum_right[i];
	}
	vector<long long> center_balance(m + 2);
	map<int, long long> center_sum_left;
	for (auto x : center)
	{
		center_sum_left[x.first] += x.second - x.first + 1;
		center_balance[x.first] += 1;
		center_balance[x.second + 1] -= 1;
	}

	vector<long long> bw_left(m + 1);
	for (auto x : bw)
	{
		bw_left[x.first] += m - x.second + x.first;
	}

	for (int j = 0; j < m;j++)
	{
		bw_left[j + 1] += bw_left[j];
	}

	vector<long long> bw_balance(m + 2);
	long long bw_xxx = 0;
	for (auto x : bw)
	{
		bw_xxx += x.first;
		bw_balance[x.first] -= 1;
	}
	for (int j = m - 1; j >= 0; j--)
	{
		bw_balance[j] += bw_balance[j + 1];
	}
	for (int j = 1; j <= m; j++)
	{

		center_balance[j] += center_balance[j - 1];
		
	}
	long long sum_left = 0, sum_center = 0, sum_bw = 0;
	long long max_res = 0;
	long long best_sum = 10000000000000000LL;
	long long save = 0, save_acc = 0;
	for (int f = 1; f <= m; f++)
	{
		long long curr_sum = sum_left + sum_right[f];
		sum_center += center_sum_left[f];

		curr_sum += sum_center + bw_xxx;

		curr_sum += bw_left[f - 1] - save_acc;// -bw_end[f];

#if 0
		int real = 0;
		for (int j = 0; j + 1 < n; j++)
		{
			int from = x[j], to = x[j + 1];
			if (to > from)
			{
				int tmp = abs(to - from);
				if (f <= to)
					tmp = min(tmp, 1 + abs(to - f));
				real += tmp;
			}
			else
			{
				int tmp = m - from + to;
				if (f <= to)
				{
					tmp = min(tmp, 1 + (to - f));
				}
				if (f > from)
					tmp = min(tmp, 1 + (m - f + to));
				real += tmp;
			}
		}

		if (real != curr_sum)
			throw 1;
#endif


		best_sum = min(best_sum, curr_sum);

		sum_center -= center_balance[f];
		sum_left += end_left[f];
		bw_xxx += bw_balance[f];
		save += bw_start[f];
		save_acc += save;
	}

	cout << best_sum;

	return 0;
}

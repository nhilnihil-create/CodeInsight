#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N;
	string S;
	cin >> N >> S;

	auto num = 0;
	auto pre = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (S[i] == ')')
		{
			if (num > 0)
			{
				--num;
			}
			else
			{
				++pre;
			}
		}
		else
		{
			++num;
		}
	}

	for (auto i = 0; i < pre; ++i)
	{
		cout << "(";
	}
	cout << S;
	for (auto i = 0; i < num; ++i)
	{
		cout << ")";
	}
	cout << endl;

	return 0;
}
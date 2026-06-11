#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	vector<bool> classes(8, false);
	int N; cin >> N;
	int overNum = 0;
	for (int i = 0; i < N; ++i)
	{
		int a; cin >> a;
		if (a >= 3200)
		{
			++overNum;
		}
		else
		{
			classes[a / 400] = true;
		}
	}
	int classNum = count(classes.begin(), classes.end(), true);
	cout << max(1, classNum) << ' ' << classNum + overNum << endl;
}

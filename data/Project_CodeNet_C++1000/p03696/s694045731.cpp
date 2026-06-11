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
	int N; cin >> N;
	string S; cin >> S;
	int sum = 0;
	string ans;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == '(') ++sum;
		else --sum;
		if (sum < 0)
		{
			ans = '(' + ans + ')';
			sum = 0;
		}
		else
		{
			ans += S[i];
		}
	}
	while (sum > 0)
	{
		ans += ')';
		--sum;
	}
	cout << ans << endl;
}

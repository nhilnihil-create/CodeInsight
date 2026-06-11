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

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
	int N; LLONG K; cin >> N >> K;
	map<int, LLONG> val2NumMap;
	REP(i, N)
	{
		int ai; LLONG bi; cin >> ai >> bi;
		val2NumMap[ai] += bi;
	}
	LLONG totalNum = 0;
	for (const auto &kvp : val2NumMap)
	{
		totalNum += kvp.second;
		if (totalNum >= K)
		{
			cout << kvp.first << endl;
			break;
		}
	}
}

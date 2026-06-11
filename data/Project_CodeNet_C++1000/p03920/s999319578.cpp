#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int N;
	cin >> N;
	vector<int> dp;
	int tmp = 2, res = 1;
	while(res <= 1e7)
	{
		dp.push_back(res);
		res += tmp++;
	}
	while(N > 0)
	{
		int k = lower_bound(dp.begin(), dp.end(), N)-dp.begin()+1;
		if (k == 0) break;
		cout << k << endl;
		N -= k;
	}
}

int main()
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}

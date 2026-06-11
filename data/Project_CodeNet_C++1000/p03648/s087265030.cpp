#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

ll k;

int main()
{
	cin >> k;

	vector<ll> ans;
	ll start = k / 50;

	ll era = 50 + start - k % 50;

	for(int i = 0;i < 51;i++)
	{
		if(start + i != era)
		{
			ans.push_back(start + i);
		}
	}

	cout << 50 << endl;

	for(int i = 0;i < 50;i++)
	{
		cout << ans[i] << " ";
	}

	cout << endl;
	return 0;




}

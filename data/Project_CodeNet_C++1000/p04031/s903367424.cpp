#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int > a(n);
	for(auto &it: a)
	{
		cin >> it;
	}
	
	int res = INT_MAX;
	for(int i = -100; i <= 100; i++)
	{
		int curr = 0;
		for(auto it: a)
		{
			curr += (pow(abs(i - it), 2));
		}
		
		res = min(res, curr);
	}
	
	cout << res;
	return 0;
}
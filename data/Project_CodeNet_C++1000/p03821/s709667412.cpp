#include <bits/stdc++.h>

using namespace std;

int main() 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	long long int a,b;
	vector <pair<long long int,long long int>> v;
	long long int res = 0;
	long long int sum = 0;
	
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}
	
	for(int i=n-1;i>=0;i--)
	{
		long long int val = (v[i].first + sum)%v[i].second;
		if(val==0)
		{
			continue;
		}
		res += (v[i].second - val);
		sum += (v[i].second - val);
	}
	
	cout << res << '\n';
	
	return 0;
}
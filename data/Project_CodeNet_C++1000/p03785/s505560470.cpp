#include <bits/stdc++.h>
 
using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	long long int c,k,t;
	vector <long long int> v;

	cin >> n >> c >> k;

	for(int i=0;i<n;i++)
	{
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(),v.end());

	int res = 1;
	long long int time = 0;
	long long int num = 1;

	time = v[0] + k;

	for(int i=1;i<n;i++)
	{
		if(time < v[i])
		{
			res++;
			num = 1;
			time = v[i] + k;
		}
		else
		{
			if(num == c)
			{
				res++;
				num = 1;
				time = v[i] + k;
			}
			else
			{
				num += 1;
			}
		}
	}

	cout << res << '\n';
	
	return 0;
}
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<bitset>
#include<list>
#include<cassert>
#include<numeric>
#include<iomanip>

using namespace std;

int n, l, t;
vector <int> finish;

int main()
{
	cin >> n >> l >> t;
	int one = 0;
	for (int i = 0; i < n; i++)
	{
		int a, d;
		cin >> a >> d;
		if (d == 1)
		{
			finish.push_back((a + t) % l);
			if (t >= l - a) 
			{
				one += (t - (l - a)) / l + 1;
			}
		}
		else 
		{
			finish.push_back(((a - t) % l + l) % l);	
			if (t > a) 
			{
				one -= (t - a - 1) / l + 1;
			}
		}
	}
	one = ((one % n) + n) % n;
	sort(finish.begin(), finish.end());
	for (int i = one; i < n; i++)
	{
		cout << finish[i] << endl;
	}
	for (int i = 0; i < one; i++)
	{
		cout << finish[i] << endl;
	}
}


 
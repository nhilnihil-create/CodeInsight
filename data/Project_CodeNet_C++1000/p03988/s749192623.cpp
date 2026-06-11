#include <bits/stdc++.h>
#define PB push_back
#define LL long long
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;
int a[105];
map<int , int> m;
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	sort(a , a + n);
	int diam = a[n - 1];
	if(a[0] < (diam + 1) / 2)
	{
		cout << "Impossible";
		return 0;
	}
	for(int i = (diam + 1) / 2; i <= diam; i++)
	{
		if(i == diam / 2)
		{
			m[i]--;
			if(m[i] < 0)
			{
				cout << "Impossible";
				return 0;
			}
		}
		else
		{
			m[i] -= 2;
			if(m[i] < 0)
			{
				cout << "Impossible";
				return 0;
			}
		}
	}
	if(m[(diam + 1) / 2])
	{
		cout << "Impossible";
		return 0;
	}
	cout << "Possible";
}
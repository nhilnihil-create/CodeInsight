#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll t;
ll a[100010];

ll rmax[100010];

ll INF = 1e18;
int main()
{
	cin >> n >> t;
	
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	for(int i = n - 1;i >= 0;i--)
	{
		rmax[i] = max(rmax[i + 1],a[i]);
	}

	int MAX = 0;
	int cou = 0;
	for(int i = n - 1;i >= 0;i--)
	{
		int dif = rmax[i] - a[i];
		//cout << dif << endl;
		if(MAX < dif)
		{
			MAX = dif;
			cou = 1;
		}
		else if(MAX == dif)
		{
			cou++;
		}
		//cout << cou << endl;
	}
	cout << cou << endl;
	return 0;



}

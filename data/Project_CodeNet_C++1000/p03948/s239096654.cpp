#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,t;
	cin >> n >> t;
	long long minx;
	long long a;
	cin >> a;
	minx = a;
	map<long long,int> m;
	long long ans = 0;
	for(int i = 2; i <= n; i++)
	{
		cin >> a;
		if(minx < a) 
		{
			m[a-minx]++;
			ans = max(ans,a-minx);
		}
		else
		{
			minx = a;
		}
	}
	cout << m[ans] << endl;
	return 0;
}
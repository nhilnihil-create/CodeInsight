#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
 
const int maxn = 2e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int last = 0 , res = 0;
	for(int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		p--;

		if(p == i)
			last++;
		else
		{
			res += (last + 1) / 2;
			last = 0;
		}
	}

	res += (last + 1) / 2;
	cout << res << endl;
}

















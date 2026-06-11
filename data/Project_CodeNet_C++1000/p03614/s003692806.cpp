#include<bits/stdc++.h>
#define pb push_back
#define ins insert
#define F first
#define S second
#define var auto
using namespace std;
typedef long long ll;
const int Max = 1e5 + 10;
const int Mod = 1e9 + 7;


int main()
{
	int n;cin >> n;
	bool last = false;
	int ans = 0;
	for(int i = 1; i <= n ; i++)
	{
		int p;cin >> p;
		if(p == i)
		{
			if(last)
			{
				ans++;
				last = false;
			}
			else
				last = true;
		}
		else
		{
			if(last)
			{
				ans++;
				last = false;
			}
		}
	}
	cout << ans + int(last) << '\n';;
}


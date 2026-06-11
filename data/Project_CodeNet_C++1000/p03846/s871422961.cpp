#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n,t = 1000000007,a[100000],ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	if (a[1] == 0)
		{
			for (int i = 2; i <= n; i++)
				{
					if (i % 2 == 0)
						{
							if (a[i] - a[i-1] != 2)
								{
									cout << 0 << endl;
									return 0;
								}
						}
					if (i % 2 == 1)
						{
							if (a[i] != a[i-1])
								{
									cout << 0 << endl;
									return 0;
								}
						}	
				}
		}
		else
			{
				if (a[1] == 1)
					{
						for (int i = 2; i <= n; i++)
							{
								if (i % 2 == 1)
									{
										if (a[i] - a[i-1] != 2)
											{
												cout << 0 << endl;
												return 0;
											}
									}
								if (i % 2 == 0)
									{
										if (a[i] != a[i-1])
											{
												cout << 0 << endl;
												return 0;
											}
									}	
							}
					}
					else	
						{
							cout << 0 << endl;
							return 0;
						 } 
			}
	n /= 2;
	for (int i = 1; i <= n; i++) ans = ans * 2 % t;
	cout << ans << endl;
	return 0;
 } 
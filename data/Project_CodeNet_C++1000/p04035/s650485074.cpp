#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int main()
{
	lli a, b; cin >> a >> b;
	lli arr[a + 50], mx = 1;
	for(int i=0; i<a; i++)
	{
		cin >> arr[i];
		if(i)
		{
			if(arr[i] + arr[i - 1] > arr[mx] + arr[mx - 1])
			{
				mx = i;
			}
		}
	}
	if(arr[mx] + arr[mx - 1] < b)
	{
		cout << "Impossible" << '\n';
		return 0;
	}
	cout << "Possible" << '\n';
	for(int i=1; i<mx; i++)
		cout << i << '\n';
	for(int i=a - 1; i > mx; i--)
		cout << i << '\n';
	cout << mx << '\n';
	return 0;
}
#include <iostream>
using namespace std;
int n, ans = 0, j;
bool a[100005];
int main()
{
	cin >> n;
	for(int i = 1; i <=n; i++)
	{
		a[i] = false;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> j;
		if(a[j] == true)
		{
			ans++;
		}
		else
		{
			a[j] = true;
		}
	}
	if(ans % 2 == 1) ans++;
	cout << n - ans << endl;
	return 0;
}
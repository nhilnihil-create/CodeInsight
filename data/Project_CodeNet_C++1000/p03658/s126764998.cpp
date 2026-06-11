#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int n, a[51],k; cin >> n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a, a + n,greater<int>()); int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += a[i];
	}
	cout << sum;

}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin >> n;
	int a[n+1];
	int b[n+1];
	int cnt = 0;
	rep(i, n)
	{
		cin >> a[i];
	}
	rep(i , n)
	{
		if(a[a[i]] == i)
			cnt++;
	}
	cout << cnt / 2 << endl;
	return (0);
}

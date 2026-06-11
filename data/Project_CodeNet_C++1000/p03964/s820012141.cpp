#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int fn(int a, int b)
{
	int ans = a / b;
	if (a % b)
		ans++;
	return ans;
}

int32_t main()
{
	IOS;
	int n, t, a, x, y;
	cin >> n;
	cin >> t >> a;
	//int t = T,a = A;
	n--;
	while (n--)
	{
		cin >> x >> y;
		int f = max(fn(t, x), fn(a, y));
		//cout << "f " << f << endl;
		t = f * x, a = f * y;
	}
	cout << t + a << endl;

	return 0;
}
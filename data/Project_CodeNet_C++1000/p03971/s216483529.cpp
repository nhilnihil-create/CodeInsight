#include<bits/stdc++.h>
#define int long long
#define fo(i,n)   for(i=0;i<n;i++)
#define mod       1000000007
using namespace std;

int gcd(int a, int b)
{
	if (b > a)
		return gcd(b, a);
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int gcd2(int a[], int n)
{
	int res = a[0];
	for (int i = 1; i < n; i++)
	{
		res = gcd(res, a[i]);
	}
	return res;
}
int32_t main()
{

	int n, a, b;
	cin >> n >> a >> b;

	string s;
	cin >> s;
	int bcnt = 0;
	int l = s.length();
	int res = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == 'a' && res < (a + b)) {
			cout << "Yes" << endl;
			res++;
		}
		else if (s[i] == 'b' && res < (a + b) && bcnt < b)
		{
			cout << "Yes" << endl;
			bcnt++;
			res++;
		}
		else
			cout << "No" << endl;

	}
}

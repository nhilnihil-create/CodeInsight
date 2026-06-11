#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int Max = 1e5 + 5;
int lst[Max];

int main()
{
	ll n, t;
	cin >> n >> t;
	ll sum = 0, f;
	cin >> f;
	for (int i = 2;i <= n;i++)
	{
		ll r;
		scanf("%lld", &r);
		sum += min(t, r - f);
		f = r;
	}
	cout << sum + t;
}
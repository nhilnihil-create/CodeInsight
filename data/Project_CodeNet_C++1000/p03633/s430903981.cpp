#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;
const int Mod = 1e9 + 7;
int lst[Max];
int ls[Max];

ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	else return gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	ll res=1;
	for (int i = 1;i <= n;i++)
	{
		ll t;
		scanf("%lld", &t);
		res /= gcd(t, res);
		res *= t;
	}
	cout << res;

}
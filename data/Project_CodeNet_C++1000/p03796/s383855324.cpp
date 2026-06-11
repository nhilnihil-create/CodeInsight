#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e9 + 7;

int main()
{
	int n;
	cin >> n;
	ll res = 1;
	for (int i = 1; i <= n; i++)
	{
		res *= i;
		res %= Max;
	}
	cout << res;
}
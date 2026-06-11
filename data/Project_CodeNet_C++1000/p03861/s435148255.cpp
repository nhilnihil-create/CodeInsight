#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e6 + 5;

int main()
{
	ll l, r, x;
	cin >> l >> r >> x;
	ll res = (r / x) - (l / x);
	if (l % x == 0 )res++;
	cout << res << endl;
}
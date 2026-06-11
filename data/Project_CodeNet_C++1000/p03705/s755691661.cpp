#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	ll n, a, b;
	cin >> n >> a >> b;
	cout << max(0LL,(b * (n - 1) + a) - (a * (n - 1) + b) + 1) << endl;
}
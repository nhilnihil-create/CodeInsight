#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, X, ans = 0;
ll f(ll a, ll b)
{
	if (!a) return -b;
	if (!b) return -a;
	if (a < b) return f(a, b % a) + b / a * a * 2ll;
	else return f(a % b, b) + a / b * b * 2ll;
}

int main()
{
	cin >> N >> X;
	cout << f(X, N - X) + N << endl;
	
	return 0;
}
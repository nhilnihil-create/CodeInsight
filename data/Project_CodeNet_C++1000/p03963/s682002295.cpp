#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int kaijo(int n)
{
	if (n == 1)
		return 1;
	return (n * kaijo(n - 1));
}

int main()
{
	int n,k;
	cin >> n >> k;
	cout << k * (int)pow(k-1,n-1) << endl;
	return (0);
}

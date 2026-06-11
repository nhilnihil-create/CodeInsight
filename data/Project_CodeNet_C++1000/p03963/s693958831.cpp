#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;

int main()
{
	int n, k;
	cin >> n >> k;
	if (k == 2) cout << 2 << endl;
	else
	{
		ll res = k;
		res *= pow(k - 1, n - 1);
		cout << res << endl;
	}

}
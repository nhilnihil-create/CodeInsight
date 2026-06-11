#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>

using namespace std;
typedef long long  ll;

int main()
{
	ll N;
	cin >> N;
	vector<ll> a(N), b(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> a[i] >> b[i];
	}
	ll npush = 0;
	for (ll i = N - 1; i >= 0; i--)
	{
		if ((npush + a[i]) % b[i] != 0)
		{
			npush += b[i] - (npush + a[i]) % b[i];
		}
	}
	cout << npush << endl;
	return 0;
}
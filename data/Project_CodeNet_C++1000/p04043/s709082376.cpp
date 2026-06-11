#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int ll;
#define mod 1000000007


void solve()
{
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];

	sort(arr, arr + 3);

	if (arr[0] == 5 && arr[1] == 5 && arr[2] == 7)
		cout << "YES";
	else
		cout << "NO";
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("1input.txt", "r", stdin);
	freopen("1output.txt", "w", stdout);
#endif

	int t = 1;
	// cin >> t;

	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}
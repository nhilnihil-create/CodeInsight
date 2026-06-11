#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int Mod = 1e9+7;

long long a[N], cnt[N];

int main ()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0 ; i < n ;  i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if ((a[i]%2 == n%2)) {
			cout << 0 << endl;
			return 0;
		}
	}
	if ((cnt[0] && n%2==0) || cnt[0] > 1) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 1; i < n; i++) {
		if (cnt[i] && cnt[i]!=2) {
			cout << 0 << endl;
			return 0;
		}
	}
	
	long long res = 1;
	for (int i = 0 ;  i< n/2 ; i++) {
		res *= 2;
		res %= Mod;
	}
	cout << res << endl;
	return 0;
}

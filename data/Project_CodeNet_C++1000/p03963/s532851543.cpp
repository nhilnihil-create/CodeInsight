#include <bits/stdc++.h>

#define fr first
#define sc second
#define mk make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int N = 1e6 + 5;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = 1;
	for (int i = 1; i < n; i ++)
		ans *= k - 1;
	ans *= k;
	cout << ans << endl;
	return 0;
}

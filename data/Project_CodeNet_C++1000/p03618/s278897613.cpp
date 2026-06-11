#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    string a;
    cin >> a;
    int n = a.size();
    vector<int> counter(1 << 8, 0);

    ll ans = 1;
	rep(i,n) {
		ans += i - counter[a[i]];
		counter[a[i]]++;
	}
	cout << ans << endl;
}
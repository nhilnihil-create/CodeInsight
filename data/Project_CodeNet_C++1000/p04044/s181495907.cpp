#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// INT VS LL

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l;
    cin >> n >> l;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (auto s: a) {
    	cout << s;
    }

    return 0;
}
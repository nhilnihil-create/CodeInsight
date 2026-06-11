#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;

    int odd = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (a[i] % 2 == 1) {
            odd++;
        }
    }

    if (odd % 2 == 1) {
        puts("NO");
    } else {
        puts("YES");
    }
}
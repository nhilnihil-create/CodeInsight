#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n;   ll ans = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; ) {
        ll tmp = 0;
        int j = i;
        while (j < n && a[j] > 0) {
            tmp += a[j];
            j++;
        }

        ans += tmp / 2;
        i = j+1;
    }
    cout << ans << endl;
    return 0;
}
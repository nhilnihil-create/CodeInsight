#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    vector<int> a(n);
    bool ok = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 2) ok = true;
        a[i]--;
    }
    if (!ok) {
        cout << "-1" << endl;
        return 0;
    }

    int button = 0;
    int count = 1;
    while (a[button] != 1 && count <= n) {
        button = a[button];
        count++;
    }
    if (a[button] == 1) {
        cout << count << endl;
    }
    else {
        cout << "-1" << endl;
    }
}
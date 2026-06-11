#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    int n;
    cin >> n;
    ll p[n], cnt0 = 0, cnt2 = 0, cnt4 = 0;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        ll cnt = 0;
        while (a % 2 == 0) {
            a /= 2;
            cnt++;
        }
        p[i] = cnt;
        if (cnt >= 2) cnt4++;
        else if (cnt == 1) cnt2++;
        else cnt0++;
    }
    if (cnt4 >= cnt0 || (cnt2 == 0 && cnt4 + 1 >= cnt0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
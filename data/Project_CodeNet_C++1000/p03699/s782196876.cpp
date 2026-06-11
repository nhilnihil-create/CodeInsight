#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n;
    int sum = 0, a = 101;
    for (int i = 0; i < n; i++) {
        cin >> s;
        sum += s;
        if (s%10 != 0) a = min (a, s);
    }
    if (sum%10 != 0) cout << sum << endl;
    else if (a == 101) cout << 0 << endl;
    else cout << sum-a << endl;
}
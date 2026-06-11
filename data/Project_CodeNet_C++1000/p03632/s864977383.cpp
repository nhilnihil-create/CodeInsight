#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int a, b, c, d; cin >> a >> b >> c >> d;

    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (c <= i && i <= d) {
            cnt++;
        }
    }

    cout << max(0, cnt - 1) << endl;
    return 0;
}
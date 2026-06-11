#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int d = 10, p[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000}, z = 0;
    char c;
    for (int i = 0; i < 10; i++) {
        cout << '?' << ' ' << p[i] << endl;
        cin >> c;
        if (c == 'N') {d = i; break;}
    }
    if (d == 10) {
        for (int i = 1; i < 10; i++) {
            cout << '?' << ' ' << p[i] - 1 << endl;
            cin >> c;
            if (c == 'Y') {cout << '!' << ' ' << p[i - 1] << endl; return 0;}
        }
        cout << '!' << ' ' << 1000000000 << endl;
        return 0;
    }
    for (int i = 0; i + 1 < d; i++) {
        int l = 0, r = 10;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            cout << '?' << ' ' << z + m << endl;
            cin >> c;
            if (c == 'Y') l = m;
            else r = m;
        }
        z += l;
        z *= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (!i && !z) continue;
        cout << '?' << ' ' << (ll)z * 10 + i * 10 << endl;
        cin >> c;
        if (c == 'Y') {z += i; break;}
    }
    cout << '!' << ' ' << z << endl;
}

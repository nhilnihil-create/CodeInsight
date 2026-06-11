#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int x, a, b;
    cin >> x >> a >> b;

    int na = a * -1;
    int nb = na + b;

    if (nb < 1) {
        cout << "delicious";
    } else {
        if (nb <= x) {
            cout << "safe";
        } else {
            cout << "dangerous";
        }
    }
    cout << endl;

    return 0;
}

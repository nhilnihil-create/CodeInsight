#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    char a, b;
    cin >> a >> b;

    if (a == 'H') {
        if (b == 'H') {
            cout << 'H';
        } else {
            cout << 'D';
        }
    } else {
        if (b == 'H') {
            cout << 'D';
        } else {
            cout << 'H';
        }
    }

    return 0;
}

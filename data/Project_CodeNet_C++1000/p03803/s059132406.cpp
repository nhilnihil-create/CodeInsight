#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "Draw";
    } else {
        if (a == 1) cout << "Alice";
        else if (b == 1) cout << "Bob";
        else cout << (a > b ? "Alice" : "Bob");
    }
    cout << endl;

    return 0;
}

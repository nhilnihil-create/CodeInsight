
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    if (a == 1 || b == 1) {
        if (a == 1 && b == 1)
            cout << "Draw" << endl;
        else if (a == 1)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    } else {
        if (a > b)
            cout << "Alice" << endl;
        else if (a < b)
            cout << "Bob" << endl;
        else
            cout << "Draw" << endl;
    }

    return 0;
}


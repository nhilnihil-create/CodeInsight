
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    if (a == 'H') {
        cout << b << endl;
    } else {
        if (b == 'H')
            cout << 'D' << endl;
        else
            cout << 'H' << endl;
    }

    return 0;
}


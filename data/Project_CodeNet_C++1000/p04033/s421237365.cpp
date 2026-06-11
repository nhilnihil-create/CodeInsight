#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (a > 0 && b > 0) cout << "Positive" << endl;
    else if (a <= 0 && b >= 0) cout << "Zero" << endl;
    else {
        if ((b - a) % 2 == 0) cout << "Negative" << endl;
        else cout << "Positive" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a * b >= c * d)
        cout << a * b << endl;
    else
        cout << c * d << endl;

    return 0;
}

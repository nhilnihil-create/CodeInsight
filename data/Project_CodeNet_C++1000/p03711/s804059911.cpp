#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int a[7] = {1, 3, 5, 7, 8, 10, 12};
    int b[4] = {4, 6, 9, 11};

    if (count(a, a + 7, x) + count(a, a + 7, y) == 2)
        cout << "Yes" << endl;
    else if (count(b, b + 4, x) + count(b, b + 4, y) == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

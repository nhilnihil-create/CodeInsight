#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y; cin >> x >> y;
    //           0   1  2  3  4  5  6  7  8  9  10 11 12
    int a[13] = {-1, 0, 1, 0, 2, 0, 2, 0, 0, 2, 0, 2, 0};
    cout << (a[x] == a[y] ? "Yes" : "No") << endl;
}

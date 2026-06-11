#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, y; cin >> x >> y;
    if (x == 2 && y == 2) puts("Yes");
    else if (x == 4 || x == 6 || x == 9 || x == 11) {
        if (y == 4 || y == 6 || y == 9 || y == 11) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    else {
        if (y == 4 || y == 6 || y == 9 || y == 11) {
            puts("No");
        }
        else {
            if (x == 2 || y == 2) puts("No");
            else puts("Yes");
        }
    }
}

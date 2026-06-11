#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

string win = "Alice";
string lose = "Brown";

long long X, Y;

int issente[210][210];
int naive(int a, int b) {
    if (a <= 1 && b <= 1) return issente[a][b] = 0;
    if (issente[a][b] != -1) return issente[a][b];
    issente[a][b] = 0;
    for (int sa = 1; sa * 2 <= a; ++sa) {
        if (naive(a - sa*2, b + sa) == 0) issente[a][b] = 1;
    }
    for (int sb = 1; sb * 2 <= b; ++sb) {
        if (naive(a + sb, b - sb*2) == 0) issente[a][b] = 1;
    }
    return issente[a][b];
}

string solve() {
    if (X <= 1 && Y <= 1) return lose;
    if (abs(X - Y ) <= 1) return lose;
    return win;
}

int main() {
    /*
    memset(issente, -1, sizeof(issente));
    for (int a = 0; a < 100; ++a) {
        for (int b = 0; b < 100; ++b) {
            if (naive(a, b) == 0) cout << a << ", " << b << endl;
        }
    }
     */
    
    while (cin >> X >> Y) {
        cout << solve() << endl;
    }
}

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <tuple>
#include <string.h>
#include <map>
#include <iomanip>
#include <time.h>
using namespace std;
typedef long long ll;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    ll p[505][505], s = 0, mx = 1e9, k;
    if (mx % (c * d) == 0) k = mx / (c * d) - 1;
    else k = mx / (c * d);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (i % c == c - 1 && j % d == d - 1) {
                p[i][j] = - k * (c * d - 1) - 1;
            }
            else p[i][j] = k;
            s += p[i][j];
        }
    }

    if (s > 0) {
        cout << "Yes" << endl;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (j != 0) cout << " ";
                cout << p[i][j];
            }
            cout << endl;
        }
    }
    else cout << "No" << endl;
}

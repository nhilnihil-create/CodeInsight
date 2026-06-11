#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr ll mod = 1000000007;

int main() {
    int n, x;
    cin >> n >> x;
    if (n == 2) {
        if (x == 2) cout << "Yes" << endl << 1 << endl << 2 << endl << 3 << endl;
        else cout << "No" << endl;
    } else if (x == 1 || x == 2*n - 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        if (x == 2) {
            int c = 1, o[4] = {1, 0, -1, 2};
            for (int i = 1; i < 2 * n; i++) {
                if (i < n - 1 || i > n + 2) {
                    while (c >= x - 1 && c <= x + 2) c++;
                    cout << c << endl;
                    c++;
                } else {
                    cout << x + o[i - (n - 1)] << endl;
                }
            }
        } else {
            int c = 1, o[4] = {-1, 0, 1, -2};
            for (int i = 1; i < 2 * n; i++) {
                if (i < n - 1 || i > n + 2) {
                    while (c >= x - 2 && c <= x + 1) c++;
                    cout << c << endl;
                    c++;
                } else {
                    cout << x + o[i - (n - 1)] << endl;
                }
            }
        }
    }
}
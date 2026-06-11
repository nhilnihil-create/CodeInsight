#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REPR(i, n) for (int i = (n); i >= 0; i--)
#define ALL(x) (x).begin(), (x).end()
#define OUT(x) std::cout << (x) << std::endl
typedef long long ll;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    int a[n];
    REP(i, n) {
        cin >> a[i];
    }
    int idx = 0;
    int c[h][w];
    REP(i, h) {
        REP(j, w) {
            if (a[idx] <= 0)
                idx++;
            if (i % 2 == 0) {
                c[i][j] = idx + 1;
            } else {
                c[i][w - j - 1] = idx + 1;
            }
            a[idx]--;
        }
    }
    REP(i, h) {
        REP(j, w) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
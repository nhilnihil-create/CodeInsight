#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
    const int M = 1000000007;
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int64_t r = 1;
    int d = 0;
    for (int i = 0; i < n; i++) {
        int j = i - d;
        if (i == n - 1) {
            for (int k = j; k >= 0; k--) {
                r = (r * (k + 1)) % M;
            }
            break;
        }
        if (x[i] <= j * 2) {//次のやつがこのターンではゴールできない
            r = (r * (j + 1)) % M;
            d++;
            j--;
        }
    }

    cout << r << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

const int mod = 1e9 + 7;

long long int mypow(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long int res = mypow(a, b / 2);
    res = res * res % mod;
    if (b % 2 == 1) res = res * a % mod;
    return res;
}


int main() { 
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i - 1];
    }
    sort(v.begin(), v.end());
    int flag = 1;
    if (n % 2 == 1) {
        for (int i = 0; i < n; i++) {
            if ((i + 1) / 2 * 2 != v[i]) {
                flag = 0;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i / 2 * 2 + 1 != v[i]) {
                flag = 0;
                break;
            }
        }
    }
    if (flag == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << mypow(2, n / 2) << endl;
}



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

long long int myc(long long int a, long long int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (a <= b) return 1;
    return myc(a - 1, b) + myc(a - 1, b - 1);
}

int main() {
    int n, p;
    cin >> n >> p;
    int one = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 1) {
            one++;
        } else {
            zero++;
        }
    }
    long long int res = 0;
    for (int i = 0; i <= one; i += 2) {
        res += myc(one, i) * ((long long int)1 << zero);
    }
    if (p == 1) {
        res = ((long long int)1 << n) - res;
    }
    cout << res << endl;
}

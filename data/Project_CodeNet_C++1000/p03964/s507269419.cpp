#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){

    int n; cin >> n;
    long long x = 1, y = 1;
    for (size_t i = 0; i < n; ++i) {
        int t, a;
        cin >> t >> a;
        long long n = max((x + t - 1)/t, (y + a - 1)/a);
        x = n * t;
        y = n * a;
    }
    cout << x + y;
    return 0;
}
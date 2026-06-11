#include <bits/stdc++.h>
using namespace std;

int64_t ncr (int64_t n, int64_t r) {
    double res = 1;
    for (int64_t i = 1; i <= r; ++i) 
        (res *= (n - i + 1)) /= (1.0 * i);
    return int64_t(res);
}

signed main () {
    int n, p;
    cin >> n >> p;
    int odd = 0, even = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a & 1)
            ++odd;
        else
            ++even;
    }
    int64_t twos = (int64_t(1) << int64_t(even)), res;
    if (p) {
        res = 0;
        for (int i = 1; i <= odd; i += 2) 
            res += ncr(odd, i);
    }
    else {
        res = 1;
        for (int i = 2; i <= odd; i += 2) 
            res += ncr(odd, i);
    }
    cout << twos * res << '\n';
}

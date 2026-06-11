#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long a, b, x;
    cin >> a >> b >> x;

    if (x == 1) {
        cout << b - a + 1 << endl;
        return 0;
    }
/*
    long long cnt = 0;
    long long tmp = 0;
    for (long long i = a; i <= b; i++) {
        if (i % x == 0) break;
        tmp++;
    }
    */
    //cout << a/x << endl;
    //b = b - a - tmp;
    if(a % x == 0)cout << (b / x+1) - (a / x) << endl;
    else cout << (b / x) - (a / x) << endl;
    //
}

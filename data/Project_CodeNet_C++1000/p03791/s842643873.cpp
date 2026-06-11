#include<bits/stdc++.h>
using namespace std;

int main(void) {
    constexpr long MOD = 1e9 + 7;

    long n;
    cin >> n;

    vector<long> x(n);
    for(auto &e: x) cin >> e;
    // | # . # . # .
    // 0 1 2 3 4 5 6

    long c = 0;
    long r = 1;
    for(long i=0; i<n; i++) {
        if(2*c+1 <= x[i]) {
            c++;
        } else {
            r *= c+1, r %= MOD;
        }
    }

    for(long i=1; i<=c; i++)
        r *= i, r %= MOD;

    cout << r << endl;
}

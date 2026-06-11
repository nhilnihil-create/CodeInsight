#include <bits/stdc++.h>
using namespace std;

long long gcd(long long x, long long y) {
    if (x % y == 0) {
        return y;
    } else {
        return gcd(y, x % y);
    }
}

long long lcm(long long x, long long y) { 
    //return x * y / gcd(x, y);
    return x / gcd(x, y) * y;
}

int main() {
    //
    long long num;
    long long tmp1;
    long long kekka=1;

    cin >> num;

    vector<long long> vec(num);

    for (int i = 0; i < num; i++) {
        cin >> tmp1;
        kekka = lcm(kekka, tmp1);
    }

    cout << kekka;
    //
}

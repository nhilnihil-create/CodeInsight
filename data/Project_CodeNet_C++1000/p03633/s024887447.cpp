#include <iostream>
using namespace std;

long long mygcd(long long a, long long b) {
    long long r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

long long mylcm(long long a, long long b) {
    long long gcd = mygcd(a, b);

    return a / mygcd(a, b) * b;
}

int main() {
    int n;
    cin >> n;

    long long res;
    long long time;
    for (int i = 0; i < n; ++i) {
        cin >> time;
        if (i == 0) {
            res = time;
            continue;
        }
        res = mylcm(res, time);
    }

    cout << res << endl;

    return 0;
}
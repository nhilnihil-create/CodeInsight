#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int n) {
    int keta = 0;
    while (n) {
        keta++;
        n /= 10;
    }
    return keta;
}


int main() {
    ll n;
    cin >> n;

    int min = 10000000;

    for (int i = 1; i < sqrt(n) + 1; i++) {
        if (n%i == 0) {
            int x;
            x = max(f(i), f(n/i));
            if (x < min) min = x;
        }
    }

    cout << min << endl;
    return 0;
}
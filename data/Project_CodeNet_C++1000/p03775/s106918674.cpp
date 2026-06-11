#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int cal(int a) {
    int count = 0;
    int x = a;
    while (x) {
        x /= 10;
        count++;
    }
    return count;
}

int main() {
    ll N;
    cin >> N;
    int i_max = sqrt(N);
    int d = 20;
    for (int i = 1; i <= i_max; i++) {
        if (N % i == 0) {
            d = min(d, cal(N / i));
        }
    }
    cout << d << endl;
}
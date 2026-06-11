#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    long long n, m;
    long long kekka1 = 0;
    long long kekka2 = 0;
long long waru = 1000000007;

    cin >> n >> m;

    if (abs(n - m) > 1) {
        cout << 0;
        return 0;
    }else{
        kekka1 = n;
        for (int i = n-1; i > 0; i--) {
            kekka1 = (kekka1 * i) % waru;
        }

        kekka2 = m;
        for (int i = m-1; i > 0; i--) {
            kekka2 = (kekka2 * i) % waru;
        }

        kekka1 = kekka1 * kekka2 % waru;
    }

    if (abs(n - m) == 0) kekka1 = kekka1 *  2 % waru;

    cout << kekka1;
    //
}

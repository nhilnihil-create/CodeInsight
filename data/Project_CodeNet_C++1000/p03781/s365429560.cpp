#include <bits/stdc++.h>

using namespace std;

const int HUGEI = 2147483647;  // (1 << 31) - 1
const long long HUGEL = 9223372036854775807;  // (1 << 63) - 1
const string ABC = "abcdefghijklmnopqrstuvwxyz";
const int MAX = 100000;

int main(void) {
    int x, i;
    cin >> x;
    long long su = 0;
    for (i = 0; i < MAX; i++) {
        su += i;
        if (su >= x) {
            break;
        }
    }
    cout << i << endl;
    return 0;
}

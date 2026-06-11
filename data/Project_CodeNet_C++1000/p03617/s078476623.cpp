#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll Q, H, S, D;
    ll N;
    ll one, two;
    cin >> Q >> H >> S >> D >> N;
    one = min(min(4 * Q, 2 * H), S);
    two = min(D, 2 * one);
    cout << (N / 2) * two + (N % 2) * one << endl;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <array>
#include <vector>
#include <utility>
#include <bitset>
#include <queue>

using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X, Y;
    cin >> X >> Y;

    cout << (abs(X - Y) <= 1 ? "Brown" : "Alice") << endl;
    return 0;
}


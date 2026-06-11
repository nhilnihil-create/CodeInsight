#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    cout << max(0, min(B, D) - max(A, C));

    return 0;
}
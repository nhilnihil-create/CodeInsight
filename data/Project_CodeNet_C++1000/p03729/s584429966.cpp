#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
using ll = long long;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    if (A.back() == B.front() && B.back() == C.front()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ALL(vec) vec.begin(), vec.end()
#define rALL(vec) vec.rbegin(), vec.rend()
using namespace std;
using ll = long long;
// ------------------------------

int cnt = 0;

int func(int A, int B, int C) {
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) return cnt;
    if (A == B && A == C) return -1;
    cnt += 1;
    return func((A + B)/2, (B + C)/2, (C + A)/2);
}

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << func(A, B, C) << endl;
    return 0;
}
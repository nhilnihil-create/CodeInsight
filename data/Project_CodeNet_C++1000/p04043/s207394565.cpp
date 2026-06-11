//(UNCOMMENT WHEN SUBMITTING)
//#pragma GCC optimize("O3")

//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)
// #pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

// clang-format off
#define range(i) for (int _ = 0; _ < i; _++)
#define vprnt(v) for (auto vi : v) cout << vi << " "; cout << endl;
#define fastio() ios::sync_with_stdio(false); cin.tie(0)
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace ::std;
int nxt() {int x;cin >> x;return x;}
ll nxtll() {ll x;cin >> x;return x;}
// clang-format on

int main() {
    fastio();

    vector<int> A(3);
    generate(all(A), nxt);
    sort(all(A));
    if (A[0] == 5 && A[1] == 5 && A[2] == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

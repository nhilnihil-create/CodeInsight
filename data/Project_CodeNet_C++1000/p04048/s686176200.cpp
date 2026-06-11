#include <bits/stdc++.h>
using namespace std;
using Int = long long;
int main() 
{
    Int N, X; cin >> N >> X;
    Int ans = N;
    Int A = X, B = N - X;
    while (B) {
        if (A > B) swap(A, B);
        ans += B / A * A * 2;
        B %= A;
    }
    ans -= A;
    cout << ans << endl;
    return 0;
}
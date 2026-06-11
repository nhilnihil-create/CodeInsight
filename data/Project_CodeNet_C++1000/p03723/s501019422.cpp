#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll A, B, C;
    ll o = 0;
    cin >> A >> B >> C;
    if((A % 2 == 0 && B % 2 == 0 && C % 2 == 0) && (A == B && B == C)) {
        cout << -1 << endl;
    } else {
        while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0) {
            ll a = A / 2;
            ll b = B / 2;
            ll c = C / 2;
            A = b + c;
            B = a + c;
            C = a + b;
            o++;
        }
        cout << o << endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using llong = long long;

llong solve(vector<llong>& a, vector<llong>& S, llong signS0=+1) {

    llong op = 0;
    S[0] = a[0];
    if (S[0]*signS0 <= 0) {
        op = abs(S[0]) + 1;
        S[0] = signS0;
    }

    for (size_t i=0; i<a.size()-1; ++i) {
        S[i+1] = S[i] + a[i+1];
        if (S[i+1] == 0) {
            S[i+1] = -(S[i] / abs(S[i]));
            ++op;
        }
        else {
            if(S[i+1]*S[i] > 0) {
                op = op + abs(S[i+1]) + 1;
                // set to +1 or -1.
                S[i+1] = - (S[i+1] / abs(S[i+1]));
            }
        }
    }
    return op;
}

int main() {
    uint n;
    cin >> n;
    vector<llong> a(n, 0);
    vector<llong> S(n, 0);
    for (auto &x: a) cin >> x;

    llong op1 = solve(a, S, +1);
    llong op2 = solve(a, S, -1);
    llong op;
    if (op1 < op2) op = op1;
    else op = op2;
    cout << op << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        if (A == C && B == D) cout << B-A << endl;
        else if (A <= C && C < B && B <= D) {
                cout << B - C << endl;
        }
        else if (A <= C && D <= B) {
                cout << D - C << endl;
        }
        else if (C <= A && B <= D) {
                cout << B - A << endl;
        }
        else if (C <= A && A < D && D <= B) {
                cout << D - A << endl;
        }
        else {
                cout << 0 << endl;
        }


}

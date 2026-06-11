#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(j, m) for (int j = 0; j < (int)(m); j++)
#define rep2(i, l, n) for (int i = l; i < (int)(n); i++)


int main() {
    string A,B;
    cin >> A >> B;
    if (A.size() == B.size() + 1) {
        rep(i,B.size()) {
            cout << A[i] << B[i];
        }
        cout << A[A.size() - 1] << endl;
    }
    else {
        rep(i,A.size()) {
            cout << A[i] << B[i];
        }
        cout << endl;
    }
}


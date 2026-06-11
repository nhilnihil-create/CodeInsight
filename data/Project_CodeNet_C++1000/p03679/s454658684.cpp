#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int X, A, B;
    cin >> X >> A >> B;
    if(-A + B <= 0) cout << "delicious" << endl;
    else if(-A + B <= X) cout << "safe" << endl;
    else cout << "dangerous" << endl;
}

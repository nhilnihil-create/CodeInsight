#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int A, B;
    char op;
    cin >> A >> op >> B;
    if(op=='+') cout << A + B << endl;
    else cout << A - B << endl;
}

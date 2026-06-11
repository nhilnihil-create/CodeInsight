#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b + c - max(a, max(b, c)) << endl;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    int A, B;
    cin >> A >> B;
    A += B;
    if(A >= 24) A -= 24;
    cout << A << "\n";
    return 0;
}
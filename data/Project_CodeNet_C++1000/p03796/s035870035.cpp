#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n = 1000000007;

ll a(int x) {
    if (x == 0) return 1;
    return x * a(x - 1) % n;
}

int main() {
    int N;
    cin >> N;
    cout << a(N) << endl;
    return 0;
}
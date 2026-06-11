#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m;
    cin >> n >> m;
    if (n >= m / 2) cout << m / 2;
    else cout << n + (m - n * 2) / 4;
}
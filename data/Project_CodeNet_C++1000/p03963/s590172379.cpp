#include <bits/stdc++.h>
using namespace std;
long long color(int n, int k) {
    if (n == 1) return k;
    else return color(n - 1, k) * (k - 1);
}
int main() {
    int n, k;
    cin >> n >> k;
    cout << color(n, k);
}
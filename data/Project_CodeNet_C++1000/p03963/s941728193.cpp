#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, ans = 1;
    cin >> n >> k;
    ans = k * pow(k - 1, n - 1);
    cout << (int)ans << endl;
}
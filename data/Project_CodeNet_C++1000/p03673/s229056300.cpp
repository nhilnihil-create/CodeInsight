#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto i = 0; i < n; i++) cin >> a[i];
    for (auto i = 0; i <= n / 2; i++) b[i] = a[n - 2 * i - 1];
    for (auto i = 0; i < n / 2; i++) b[n - i - 1] = a[n - 2 * i - 2];
    for (auto i = 0; i < n; i++) cout << b[i] << " ";
    cout << endl;
    return 0;
}
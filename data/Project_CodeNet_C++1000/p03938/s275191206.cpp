#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 1e5+5;
int n, p[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        p[x] = i;
    }
    vector<int> a(n), b(n);
    b[0] = n * n + 5;
    for(int i = 1; i < n; i++) b[i] = b[i - 1] - n;
    a[0] = 1;
    for(int i = 1; i < n; i++) {
        int d = p[i] - p[i - 1];
        a[i] = a[i-1] + n + d;
    }
    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
    for(int i = 0; i < n; i++) cout << b[i] << " ";
    return 0;
}
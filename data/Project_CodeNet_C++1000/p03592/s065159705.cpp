#include<iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    cin.sync_with_stdio(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    bool ok = false;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int b = i * (m - j) + j * (n - i);
            if (b == k) ok = true;
        }
    }

    cout << (ok ? "Yes" : "No") << endl;

}
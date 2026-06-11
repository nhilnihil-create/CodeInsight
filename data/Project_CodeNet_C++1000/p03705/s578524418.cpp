#include <bits/stdc++.h>

using namespace std;


int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    bool ok = true;
    if(a > b) {
        ok = false;
    }
    if(a != b && n == 1) {
        ok = false;
    }
    if(!ok) {
        cout << 0 << "\n";
        return 0;
    }
    long long mini = a * (n - 1) + b;
    long long maxi = b * (n - 1) + a;
    cout << maxi - mini + 1 << "\n";
}
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

#define int long long

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, L;   
    cin >> n >> L; 
    vector <int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    bool good = false;
    int pos = -1;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] + a[i + 1] >= L) good = true, pos = i;
    }
    if (!good) {
        cout << "Impossible\n";
        return 0;
    }
    cout << "Possible\n";
    for (int i = 0; i < pos; i++) {
        cout << i + 1 << '\n';
    }
    for (int i = n - 2; i >= pos + 1; i--) {
        cout << i + 1 << '\n';  
    }
    cout << pos + 1 << '\n';
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    int cnt_odd = 0;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a%2) cnt_odd++;
    }
    long long ans;
    if (cnt_odd == 0) {
        if (p == 0) ans = pow(2, n);
        else ans = 0;
    }
    else {
        ans = pow(2, n-1);
    }
    cout << ans << endl;
}
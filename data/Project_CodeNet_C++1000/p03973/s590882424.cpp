#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int p = 1;
    long long ans = 0;
    while (n--) {
        int a; cin >> a;
        if (a == p) p++;
        else if (a > p) { ans += (a-1)/p; if (p == 1) p++; }
    }
    cout << ans << endl;
}

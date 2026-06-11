#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int64_t> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int64_t ans = 0;
    for (int i = n - 1; 0 <= i; --i) {
        int64_t mod = (a[i] + ans) % b[i];
        if (mod) {
            ans += b[i] - mod;
        }

        /*if (a[i] + ans <= b[i]) {
            ans += b[i] - (a[i] + ans);
        }
        else {
            auto mod = (a[i] + ans) % b[i];
            if (mod) ans += b[i] - mod;
        }*/
    }

    cout << ans << endl;
}


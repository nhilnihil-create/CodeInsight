#include <bits/stdc++.h>
using namespace std;

#define dump(x) cout << (x) << '\n'
#define Int int64_t
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
 
Int INF = 1e18;
int inf = 1e9;
Int mod = 1e9+7;

int main() {
    Int n, l;
    cin >> n >> l;
    vector<Int> a(n);
    for (Int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Int index = -1;
    bool check = false;
    for (Int i = 0; i < n - 1; i++) {
        if (a[i] + a[i + 1] >= l) {
            check = true;
            index = i;
        }
    }
    if (check) {
        dump("Possible");
        for (Int i = 0; i < index; i++) {
            dump(i + 1);
        }
        for (Int i = n - 2; i > index; i--) {
            dump(i + 1);
        }
        dump(index + 1);
    } else {
        dump("Impossible");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int64_t ans = 0;
    int64_t tmp = 0;
    REP(i, n) {
        int64_t a, b;
        cin >> a >> b;
        if(a > tmp) {
            ans = a + b;
            tmp = a;
        }
    }
    cout << ans << endl;
}

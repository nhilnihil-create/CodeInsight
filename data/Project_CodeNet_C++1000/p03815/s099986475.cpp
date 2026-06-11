#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t x;
    int64_t remains;
    int64_t ans;
    
    cin >> x;
    ans = (x / 11) * 2;

    remains = x % 11;
    if(remains == 0) {
    } else if(remains > 6) {
        ans+=2;
    } else {
        ans++;
    }

    cout << ans << "\n";
    return 0;
}

#include <iostream>
#include <cmath>
// #include <vector>
// #include <string>
// #include <algorithm>
// #include <set>
// #include <map>
// #include <iomanip>

// #define MOD 1000000007

using namespace std;
// typedef unsigned long long ull;
typedef long long ll;

void p() {
    cout << "\n";
}
template<class Head, class... Body>
void p(Head head, Body... body) {
    cout << head << ",";
    p(body...);
}


int main(int argc, char const *argv[]) {
    int H, W;
    cin >> H >> W;

    int ans;
    if (H % 3 == 0 || W % 3 == 0) {
        ans = 0;
    } else {
        ans = min(H, W);
        int k, l, d;
        k = H / 3; l = (W+1) / 2; d = (H-k)*l - k*W;
        // p(k,l,d,ans);
        ans = min(ans, d);
        k = (H+2) / 3; l = W / 2; d = k*W - (H-k)*l;
        // p(k,l,d,ans);
        ans = min(ans, d);
        k = (H+1) / 2; l = W / 3; d = (W-l)*k - l*H;
        // p(k,l,d,ans);
        ans = min(ans, d);
        k = H / 2; l = (W+2) / 3; d = l*H - (W-l)*k;
        // p(k,l,d,ans);
        ans = min(ans, d);
    }
    
    cout << ans << endl;

    return 0;
}

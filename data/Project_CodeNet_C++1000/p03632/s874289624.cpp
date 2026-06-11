#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b>> c >> d;
    int left = min(a, c), right = max(b, d);
    int ans = 0;
    for (int i=left; i<=right; ++i) {
        if ((i >= a) && (i <= b) && (i>=c) && (i <=d))
            ans += 1;
    }
    cout << (ans >0 ? ans-1 : 0);
}

int main() {

	solve();
    return 0;
}

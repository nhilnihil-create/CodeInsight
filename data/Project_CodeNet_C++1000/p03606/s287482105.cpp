#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int N,a,b, ans=0;
    cin >> N;
    rep(i, N) {
        cin >> a >> b;
        ans += b-a + 1;
    }

    cout << ans << endl;
}
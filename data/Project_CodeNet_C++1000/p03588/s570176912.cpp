#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, max = 0, ans = 0;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        if(max < a) {
            max = a;
            ans = a + b;
        }
    }
    cout << ans << endl;
}

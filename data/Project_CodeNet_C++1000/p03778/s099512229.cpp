
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b, w, ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> a >> b;
    if (a > b)
        swap(a, b);
    if (b <= a + w)
        ans = 0;
    else
        ans = b - a - w;
    cout << ans << endl;

    return 0;
}


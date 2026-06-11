
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int a[N];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = 1;
    int ans = 0;
    int s = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1])
            ++cnt;
        else {
            if (cnt != 1 && (cnt & 1) == 0)
                ++s;
            ++ans;
            cnt = 1;
        }
    }
    if (cnt != 1 && (cnt & 1) == 0)
        ++s;
    ++ans;
    if (s & 1)
        --ans;

    cout << ans << endl;

    return 0;
}


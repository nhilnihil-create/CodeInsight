
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e3 + 5;
const int mod = 1e9 + 7;
int n;
int a[N];
ll cnt[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll ans = 1;
    for (int i = 2; i <= n; ++i) {
        int temp = i;
        for (int j = 2; j <= n; ++j) {
            while (temp % j == 0) {
                temp /= j;
                ++cnt[j];
            }
            if (temp == 1)
                break;
        }
    }
    for (int i = 2; i < N; ++i) {
        ans = ans * (cnt[i] + 1) % mod;
    }
    cout << ans << endl;


    return 0;
}


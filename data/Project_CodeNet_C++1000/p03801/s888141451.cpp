#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[100010];
ll b[100010];
vector<ll> v;
vector<ll> ans;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    v.push_back(0);
    ll bf = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > bf) {
            bf = a[i];
            v.push_back(bf);
        }
    }
    sort(a,a+n);

    int pos = 0;
    ll cnt = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        while (a[pos] < v[i + 1]) {
            cnt += max(0LL, a[pos] - v[i]);
            pos++;
        }
        cnt += (v[i + 1] - v[i]) * (n - pos);
        ans.push_back(cnt);
        cnt = 0;
    }

    ans.push_back(0);
    bf = 0;
    pos = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] > bf) {
            cout << ans[pos] << endl;
            pos++;
            bf = b[i];
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

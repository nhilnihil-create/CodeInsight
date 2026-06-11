#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
const int maxN = 111;
ll cnt[maxN];
bool used[maxN];
vector <int> v;

ll calc(int l, int r) {
    for (int i = 1; i <= 100; i++) {
        cnt[i] = 0;
        used[i] = 0;
    }
    ll sum = 0;
    for (int i = l; i <= r; i++) {
        ll cur = 0;
        for (int j = 1; j < v[i]; j++) {
            cur += cnt[j];
        }
        cur++;
        cnt[v[i]] += cur;
        sum += cur;
        if (sum > 1e14) {
            return 1e14;
        }
    }
    return sum;
}
int main(void) {
    ll n;
    cin >> n;
    v.push_back(1);
    vector <int> r;
    for (int j = 2; j <= 100; j++) {
           r.push_back(j);
    }
    if (n != 1) {
        for (int j = 0; j <= r.size(); j++) {
            int i = r[j];
            v.push_back(i);
            ll mx = 0;
            int pp = 0;
            vector <int> v1 = v;
            for (int p = 0; p < v.size(); p++) {
                for (int j = (int)v.size() - 2; j >= p; j--) {
                    v[j + 1] = v[j];
                }
                v[p] = i;
                ll cur = calc(0, (int)v.size() - 1);
                if (cur <= n && cur > mx) {
                    mx = max(cur, mx);
                    pp = p;
                }
                v = v1;
            }
            for (int j = (int)v.size() - 2; j >= pp; j--) {
                v[j + 1] = v[j];
            }
            v[pp] = i;
            if (mx == 99) {
                int o = 0;
            }
            fflush(stderr);
            if (mx == n) {
                break;
            }
        }
    }
    if (calc(0, v.size() - 1) != n) {
        return -1;
    }
    cout << (int)v.size() + 100 << endl;
    for (int i = 1; i <= 100LL; i++) {
        cout << i << " ";
    }
    for (auto el : v) {
        cout << el << " ";
    }
    cout << endl;
}
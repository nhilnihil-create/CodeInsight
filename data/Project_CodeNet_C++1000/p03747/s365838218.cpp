#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
const int maxn = 1e5+100;
ll n, l, t;
ll x[maxn];

//如何锁定第一只蚂蚁的位置
int main() {
  //  freopen("input.txt", "r", stdin);
    cin >> n >> l >> t;
    int w;
    ll temp;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> w;
        if (w == 1) {
            temp = x[i] + t;
            x[i] = temp % l;
            cnt += temp / l;
        } else {
            temp = x[i] - t;
            x[i] = temp % l;
            cnt += temp / l;
            if (x[i] < 0) {
                x[i] += l;
                cnt--;
            }
        }
    }
    sort(x, x + n);
    cnt %= n;
    cnt = (cnt + n) % n;
    for (int i = cnt; i < cnt + n; i++) {
        cout << x[i % n] << endl;
    }
    return 0;

}
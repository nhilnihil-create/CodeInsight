#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#undef tabr
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, l, t;
    cin >> n >> l >> t;
    vector<ll> x(n), w(n), z(n);
    vector<ll> ss, tt;
    rep(i, 0, n) {
        cin >> x[i] >> w[i];
        z[i] = x[i] + (w[i] == 1 ? t : -t);
        z[i] %= l;
        if (z[i] < 0) z[i] += l;
        if (w[i] == 1)
            ss.emplace_back(i);
        else
            tt.emplace_back(i);
    }
    if (ss.size() == 0 || tt.size() == 0) {
        rep(i, 0, n) cout << z[i] << endl;
        return 0;
    }
    if (ss[0] == 0) ss[0] = n + 1;
    sort(ss.rbegin(), ss.rend());
    ll d0;
    vector<ll> ds, dt;
    bool mae = true;
    if (ss[0] == n + 1) {
        ss[0] = 0;
        d0 = (l + x[tt[0]] - x[ss[0]]) % l;
        rep(i, 0, ss.size() - 1) {
            ds.emplace_back((l + x[ss[i]] - x[ss[i + 1]]) % l);
        }
        ds.emplace_back(l - accumulate(ds.begin(), ds.end(), 0ll));
        rep(i, 0, tt.size() - 1) {
            dt.emplace_back((l + x[tt[i + 1]] - x[tt[i]]) % l);
        }
        dt.emplace_back(l - accumulate(dt.begin(), dt.end(), 0ll));
    } else {
        d0 = (l + x[tt[0]] - x[ss[0]]) % l;
        rep(i, 0, ss.size() - 1) {
            ds.emplace_back((l + x[ss[i]] - x[ss[i + 1]]) % l);
        }
        ds.emplace_back(l - accumulate(ds.begin(), ds.end(), 0ll));
        rep(i, 0, tt.size() - 1) {
            dt.emplace_back((l + x[tt[i + 1]] - x[tt[i]]) % l);
        }
        dt.emplace_back(l - accumulate(dt.begin(), dt.end(), 0ll));
        swap(ss, tt);
        swap(ds, dt);
        mae = false;
    }
    debug(ss, tt, d0);
    if (d0 >= t * 2) {
        ll pos = z[0];
        int res;
        sort(z.begin(), z.end());
        rep(i, 0, n) {
            if (z[i] == pos) {
                res = i;
                if (mae == false && i != n - 1 && z[i + 1] == pos) res++, debug(2);
                break;
            }
        }
        rep(i, 0, n) cout << z[(i + res) % n] << endl;
        return 0;
    }
    debug(ds, dt);
    rep(i, 1, ds.size()) ds[i] += ds[i - 1];
    rep(i, 1, dt.size()) dt[i] += dt[i - 1];
    debug(ds, dt);
    ll lx = 0, rx = 2 * t + 10;
    ll sz = ss.size(), tz = tt.size();
    while (rx - lx > 1) {
        ll mid = (rx + lx) / 2, sum = d0;
        ll sc = (mid + 1) / 2, tc = mid / 2;
        sum += (sc / sz) * l;
        sc -= (sc / sz) * sz;
        sum += (tc / tz) * l;
        tc -= (tc / tz) * tz;
        if (sc) sum += ds[sc - 1];
        if (tc) sum += dt[tc - 1];
        if (sum < t * 2)
            lx = mid;
        else
            rx = mid;
    }
    debug(lx, rx);
    int res = 0;
    lx = rx;
    if (lx % 2 == 0) {
        lx /= 2;
        lx %= ss.size();
        res = ss[lx];
    } else {
        lx /= 2;
        lx %= tt.size();
        res = tt[lx];
        mae ^= 1;
    }
    debug(res);
    int pos = z[res];
    sort(z.begin(), z.end());
    rep(i, 0, n) {
        if (z[i] == pos) {
            res = i;
            if (mae == false && i != n - 1 && z[i + 1] == pos) res++, debug(2);
            break;
        }
    }
    rep(i, 0, n) {
        cout << z[(i + res) % n] << endl;
    }
    return 0;
}
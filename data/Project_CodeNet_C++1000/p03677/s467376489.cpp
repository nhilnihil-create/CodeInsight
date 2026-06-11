#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

class BIT {
    int n;
    vi data0, data1;

    void add(vi& data, int i, i64 x) {
        while (i <= n) {
            data[i] += x;
            i += i & -i;
        }
    }

    i64 sum(vi& data, int i) {
        i64 s = 0;
        while (i > 0) {
            s += data[i];
            i -= i & -i;
        }
        return s;
    }

public:
    BIT(int n) : n(n) {
        data0 = vi(n + 1);
        data1 = vi(n + 1);
    }

    // [l, r)
    void add(int l, int r, i64 x) {
        l++;
        r++;
        add(data0, l, -x * (l - 1));
        add(data1, l, x);
        add(data0, r, x * (r - 1));
        add(data1, r, -x);
    }

    // [l, r)
    i64 sum(int l, int r) {
        i64 s = 0;
        s += sum(data0, r) + sum(data1, r) * r;
        s -= sum(data0, l) + sum(data1, l) * l;
        return s;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    BIT bit(m);
    vector<int> as;
    i64 sum[101010] = {};
    {
        int a;
        cin >> a;
        a--;
        as.push_back(a);
        
        for (int i = 0; i < n - 1; i++) {
            int b;
            cin >> b;
            b--;
            as.push_back(b);
            sum[b] += (b + m - a) % m - 1;
            if (a < b) {
                bit.add(a + 1, b, 1);
            } else {
                bit.add(a + 1, m, 1);
                bit.add(0, b, 1);
            }
            a = b;
        }
    }

    i64 ans = 1e18, cur = 0;
    for (int i = 1; i < n; i++) {
        int a = as[i - 1], b = as[i];
        cur += min(1 + (b + m - 0) % m, (b + m - a) % m);
    }

    ans = cur;
    for (int i = 1; i < m; i++) {
        cur += sum[i - 1];
        cur -= bit.sum(i - 1, i);
        ans = min(ans, cur);
    }

    cout << ans << endl;
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename Abel> struct BIT {
    const Abel UNITY_SUM = 0;
    vector<Abel> dat;
    BIT(int n) : dat(n + 1, UNITY_SUM) { }  // [1, n]
    inline void add(int i, Abel x) {
        while (i < dat.size()) { dat[i] += x; i += i & -i; }
    }
    inline Abel sum(int i) {    // [1, i]
        Abel res = UNITY_SUM;
        while (i > 0) { res += dat[i]; i -= i & -i; }
        return res;
    }
    inline Abel sum(int a, int b) { return sum(b - 1) - sum(a - 1); }   // [a, b)
    /* debug */
    Abel operator[](int i) { return sum(i, i + 1); }
    void debug() {
        for (int i = 1; i < dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

template<typename T> long long inversion_number(const vector<T> &a) {
    int n = a.size();
    vector<T> b = a;
    sort(begin(b), end(b)); b.erase(unique(begin(b), end(b)), end(b));
    long long res = 0;
    BIT<int> bit(n);
    for (T ai: a) {
        int order = lower_bound(begin(b), end(b), ai) - begin(b) + 1;
        res += bit.sum(order + 1, n + 1); bit.add(order, 1);
    }
    return res;
}

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    vector<long long> acc(n + 1);
    for (int i = 0; i < n; i++) acc[i + 1] = acc[i] + a[i] - k;
    cout << 1LL * (n + 1) * n / 2 - inversion_number(acc) << endl;
    return 0;
}
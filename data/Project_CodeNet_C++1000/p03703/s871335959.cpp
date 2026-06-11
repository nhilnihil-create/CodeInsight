#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

template< typename T >
struct BinaryIndexedTree {
    vector< T > data;

    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for(++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x) {
        for(++k; k < data.size(); k += k & -k) data[k] += x;
    }
};

template< typename T >
vector<int> compress(const vector<T> &v) {
    int n = v.size();
    vector<int> res(n);
    vector< T > tmp = v;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i=0; i<n;i++) {
        res[i] = distance(tmp.begin(), lower_bound(tmp.begin(), tmp.end(), v[i]));
    }
    return res;
}

int main(void) {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> a(N+1);
    for(int i=1; i<=N; i++) {
        cin >> a[i];
        a[i] -= K;
    }

    partial_sum(a.begin(), a.end(), a.begin());

    auto cmp = compress(a);

    int64_t ans = 0;
    BinaryIndexedTree<int64_t> bit(N+1);
    for(int i=0; i<=N; i++) {
        cerr << cmp[i] << endl;
        ans += bit.sum(cmp[i]);
        bit.add(cmp[i], 1);
    }

    cout << ans << endl;
    return 0;
}

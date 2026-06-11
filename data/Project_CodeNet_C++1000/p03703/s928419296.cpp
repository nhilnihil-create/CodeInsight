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
struct Compress {
    vector< T > xs;

    Compress() = default;

    Compress(const vector< T > &vs) {
        add(vs);
    }

    Compress(const initializer_list< vector< T > > &vs) {
        for(auto &p : vs) add(p);
    }

    void add(const vector< T > &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) {
        xs.emplace_back(x);
    }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector< int > get(const vector< T > &vs) const {
        vector< int > ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const {
        return xs[k];
    }
};

int main(void) {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> a(N+1);
    for(int i=1; i<=N; i++) {
        cin >> a[i];
        a[i] -= K;
    }

    partial_sum(a.begin(), a.end(), a.begin());

    Compress<int64_t> comp;
    comp.add(a);
    comp.build();
    auto zart = comp.get(a);

    int64_t ans = 0;
    BinaryIndexedTree<int64_t> bit(N+1);
    for(int i=0; i<=N; i++) {
        ans += bit.sum(zart[i]);
        bit.add(zart[i], 1);
    }

    cout << ans << endl;
    return 0;
}

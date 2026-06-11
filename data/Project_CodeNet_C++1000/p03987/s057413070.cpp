#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

template<typename T>
struct BinaryIndexedTree {
    vector<T> data;

    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }

    T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }

    void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }

    int search_small(int index) {
        int x = sum(index);

        int ok = -1;
        int ng = index;
        while (abs(ok - ng) > 1) {
            int mid = ok + (ng - ok) / 2;

            if (sum(mid) < x)ok = mid;
            else ng = mid;
        }

        return ok;
    }

    int search_big(int index) {
        int x = sum(index);

        int ok = data.size() - 1;
        int ng = index;
        while (abs(ok - ng) > 1) {
            int mid = ok + (ng - ok) / 2;
            int count = sum(mid);
            if (count > x)ok = mid;
            else ng = mid;
        }

        return ok;
    }

    void print() {
        for (int i = 0; i < data.size(); i++) {
            if (i > 0)cout << " ";
            cout << sum(i);
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        pos[tmp] = i;
    }

    BinaryIndexedTree<int> bit(n + 1);
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        int nowpos = pos[i];
        ll s1 = bit.search_small(nowpos);
        ll b1 = bit.search_big(nowpos);

        ret += i * (b1 - nowpos) * (nowpos - s1 - 1);
        bit.add(nowpos, 1);
    }

    cout << ret << endl;
    return 0;
}
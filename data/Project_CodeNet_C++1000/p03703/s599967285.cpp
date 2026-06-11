#include <bits/stdc++.h>
using namespace std;

template<class T> struct BinaryIndexedTree {
private : 
    vector<T> data;
public :
    BinaryIndexedTree(int n) : data(n+1, 0) { }

    T get(int i) {
        T ret = 0;
        for (; i >= 0; i = (i&(i+1))-1) ret += data[i];
        return ret;
    }

    void add (int i, T x) {
        for (; i < data.size(); i |= (i+1)) data[i] += x;
    }

};

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n), s(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= k;
        s[i+1] = s[i] + a[i];
    }
    
    vector<long long> v = s;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i <= n; i++) {
        s[i] = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
    }
    
    long long ans = 0;
    BinaryIndexedTree<long long> bit(n+5);
    for (int i = 0; i <= n; i++) {
        ans += bit.get(s[i]);
        bit.add(s[i], 1);
    }
    cout << ans << endl;
    return 0;
}
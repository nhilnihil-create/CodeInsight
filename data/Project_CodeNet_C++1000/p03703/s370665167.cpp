/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.12 02:54:17
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;



template< typename T >
struct BinaryIndexedTree {
    std::vector< T > data;
    BinaryIndexedTree(int sz) {
        data.assign(++sz, 0);
    }
    
    inline T sum(int k) {
        T ret = 0;
        for (++k; k > 0; k -= k & -k) ret += data[k];
        return (ret);
    }
    
    inline T sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
    
    
    inline void add(int k, T x) {
        for (++k; k < data.size(); k += k & -k) data[k] += x;
    }
    
    
    
    int get(int64_t k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)data.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)data.size() && data[res + i] < k) {
                k = k - data[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }
    void print() {
        std::cout << "[ ";
        for (int i = 0; i < data.size() - 1; i++) {
            std::cout << sum(i, i);
            if (i < data.size() - 2) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
};
int main() {
    int n,k;cin >> n >> k;
    vector<ll> sum(n+1);
    set<pair<ll,int>> st;
    ll ans = 0;
    map<ll,int> mp; 
    mp[0LL] = 0;
    for (int i = 0; i < n; i++) {
        ll a;cin >> a;
        a -= k;
        sum[i + 1] = sum[i] + a;
        mp[sum[i+1]] = 0;
    }
    int idx = 0;
    for(auto p : mp) {
        mp[p.first] = idx++;
    }
    BinaryIndexedTree<ll> bit(idx);
    for (int i = 0; i <= n; i++) {
        ans += bit.sum(0,mp[sum[i]]);
        bit.add(mp[sum[i]],1);
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
    Int n, k;
    cin >> n >> k;
    vector<Int> a(n);
    for(auto &i:a) cin >> i;
    for(Int i=0; i<n; ++i)
        a[i] -= k;
    for(Int i=1; i<n; ++i)
        a[i] += a[i-1];
    vector<Int> b(a);
    b.push_back(0);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map<Int, Int> mp;
    for(size_t i=0; i<b.size(); ++i)
        mp[b[i]] = i+1;
//    for(size_t i=0; i<b.size(); ++i)
//        cout << i << " " << b[i] << "\n";
    vector<Int> bit(b.size()+1);
    Int m = b.size();
    for(Int i=mp[0]; i<=m; i+=i&-i) ++bit[i];
    Int ans = 0;
    for(Int i=0; i<n; ++i){
        for(Int j=mp[a[i]]; j>0; j-=j&-j) ans += bit[j];
        for(Int j=mp[a[i]]; j<=m; j+=j&-j) ++bit[j];
//        cout << i << " " << ans << "\n";
    }
    cout << ans << "\n";
}
#include <bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

using ll =long long;

using namespace std;

signed main() {
    int N, x;cin >> N >> x;
    vector<int> v;
    for(int i = 0;i < N;i++){
        int a;cin >> a;
        v.push_back(a);
    }
    ll ans = 0;
    if(v.front() >= x){
        ans += v.front() - x;
        v.front() = x;
    }
    for(int i = 1;i < N;i++){
        if(v[i - 1] + v[i] >= x){
            ans += v[i] + v[i - 1] - x;
            v[i] -= v[i] + v[i - 1] - x;
        }
    }
    cout<<ans<<endl;
}



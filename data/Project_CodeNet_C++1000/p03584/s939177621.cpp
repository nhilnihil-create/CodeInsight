#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;
using u64 = uint64_t;

u64 calc(u64 mask, const u64 n, const vector<pair<u64, u64>> &v){
    u64 sum = 0;
    for(u64 i=0;i<n;++i){
        if((v[i].first|mask) > mask)continue;
        sum += v[i].second;
    }
    return sum;
}

int main(){
    u64 n, k;
    cin >> n >> k;
    vector<pair<u64, u64>> v;
    for(int i=0;i<n;++i){
        u64 a, b;
        cin >> a >> b;
        v.emplace_back(a, b);
    }
    u64 ans = 0;
    for(u64 i=0;(1<<i)<=k;++i){
        if(((1<<i)&k) == 0)continue;
        u64 mask = ((1<<i)-1)|k;
        mask &= ((~0)^(1<<i));
        ans = max(ans, calc(mask, n, v));
    }
    ans = max(ans, calc(k, n, v));

    cout << ans << endl;

    return 0;
}

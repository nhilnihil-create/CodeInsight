#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> a){
    vector<long long> cnt(1e5);
    for(long long i = 0; i < N; ++i) cnt[a[i]] += 1;
    //for(auto itr = mp.begin(); itr != mp.end(); ++itr) cout << itr->first << " " << itr->second << endl;
    long long ans = 0;
    for(long long i = 1; i < cnt.size()-1; ++i){
        ans = max(ans, cnt[i-1]+cnt[i]+cnt[i+1]);
    }
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}

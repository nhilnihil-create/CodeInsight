#include <bits/stdc++.h>
using namespace std;


void solve(long long N, std::vector<long long> a){
    double a_mean = 0;
    long long ans = 0;
    for(auto i: a) a_mean += (double)i;
    a_mean = a_mean/(double)N;
    for(int i = 0; i < N; ++i) ans += round((double)a[i] - a_mean) * round((double)a[i] - a_mean);
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

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, long long x, std::vector<long long> A){
    vector<ll> a = A;
    ll res = 0;
    if(a[0] > x) a[0] = x;
    for(ll i = 0; i < N-1; ++i){
        if(a[i] + a[i+1] > x){
            if(a[i+1] >= a[i] + a[i+1] - x){
                a[i+1] -= a[i] + a[i+1] - x;
            }
            else{
                a[i] -= abs(a[i+1] - (a[i] + a[i+1] - x));
                a[i+1] = 0;
            }
        }
    }
    for(ll i = 0; i < N; ++i){
        res += A[i] - a[i];
    }
    cout << res << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long x;
    scanf("%lld",&x);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, x, std::move(a));
    return 0;
}

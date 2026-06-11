#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, long long M){
    ll max_val = max(M/2, N);
    ll ans;
    if(max_val == N) ans = M/2;
    else ans = N + (M/2-N)/2;
    cout << ans << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    solve(N, M);
    return 0;
}

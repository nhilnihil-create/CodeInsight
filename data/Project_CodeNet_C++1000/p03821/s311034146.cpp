#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    rep(i, 0, N) cin >> A[i] >> B[i];
    ll cnt = 0;
    for(ll i = N-1; i >= 0; i--){
        A[i] += cnt;
        if(A[i] % B[i] == 0) continue;
        ll rem = (ll)((A[i] + B[i] - 1)/B[i]) * B[i] - A[i];
        //cerr << i << ":" << rem << endl;
        cnt += rem;
    }
    cout << cnt << endl;
    return 0;
}
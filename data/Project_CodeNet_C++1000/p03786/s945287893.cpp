#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N+1), acc(N+1);
    rep(i, 1, N+1) cin >> A[i];
    sort(A.begin(), A.end());
    rep(i, 1, N+1) acc[i] = acc[i-1] + A[i];
    ll ans = 1;
    for(ll i = N-1; i > 0; i--){
        if(A[i+1] <= 2 * acc[i]){
            ans++;
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
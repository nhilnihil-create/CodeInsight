#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    // input
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    sort(A.begin(), A.end());
    
    ll i = 0;
    if(N%2 == 1){
        if(A[0] != 0){
            cout << 0 << endl;
            return 0;
        }else{
            i++;
        }
    }
    ll t;
    if(N%2 == 1) t = 2;
    else t = 1;

    while(i < N-1){
        if(A[i] == A[i+1] && A[i] == t){
            i += 2;
            t += 2;
        }else{
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = 1;
    ll mod = 1e9+7;
    rep(i, 0, N/2){
        ans *= 2;
        ans %= mod;
    } 
    cout << ans << endl;
    return 0;
}
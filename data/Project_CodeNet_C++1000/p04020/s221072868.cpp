#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    ll ans = 0;
    rep(i, 0, N){
        if(A[i] % 2 == 1 && i != N-1){
            if(A[i+1] > 0){
                A[i+1]--;
                ans++;
            }
        }
        ans += A[i] / 2;
    }
    cout << ans << endl;
    return 0;
}
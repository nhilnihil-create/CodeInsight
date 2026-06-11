#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    rep(i,N){
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for (ll i = N - 1; i >= 0; i--){
        A[i] += ans;
        if (A[i] % B[i] != 0){
            ans += (B[i] - (A[i] % B[i]));
        }
    }
    cout << ans << endl;
}
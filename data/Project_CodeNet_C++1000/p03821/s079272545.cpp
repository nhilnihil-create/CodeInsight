#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N, 0);
    vector<ll> B(N, 0);
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for(int i = N - 1; i >= 0; i--){
        A[i] += ans;
        if(A[i] % B[i] != 0){
            if(A[i] > B[i]){
                B[i] = B[i] * ((A[i] / B[i])+ 1);
            }
            ans += B[i] - A[i];
        }

    }

    cout << ans << endl;
}

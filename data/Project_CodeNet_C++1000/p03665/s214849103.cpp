#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

int main() {
    ll N, P;
    cin >> N >> P;
    ll cnt = 0;
    vector<ll> A(N,0);
    rep(i,N) cin >> A[i];
    ll ans = 0;
    rep(i,N){
        if(A[i] % 2 == 0){
            cnt++;
        }
    }
    if(cnt == N){
        if(P == 0){
            ans = pow(2,N);
        }
    }
    else{
        ans = pow(2,N - 1);
    }
    cout << ans << endl;
}

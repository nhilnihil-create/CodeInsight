#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(3 * N);
    rep(i,3 * N){
        cin >> A[i];
    }
    sort(all(A));
    ll ans = 0;
    for (ll i = 0; i < N; i++){
        ans += A[3 * N - 2 - i * 2];
    }
    cout << ans << endl;
}
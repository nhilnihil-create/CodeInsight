#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (ll i=0; i<n; ++i)
#define all(obj) (obj).begin(),(obj).end()
using namespace std;
typedef long long ll;
long long GCD(long long x, long long y) { return y ? GCD(y, x%y) : x; }

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll cnt = 0;
    ll ans = 1;
    sort(A.rbegin(), A.rend());
    rep(i, N){
        if(cnt==2) break;
        if(A[i]==A[i+1]){
            ans*=A[i];
            cnt++;
            i++;
        }
    }
    if(cnt==2) cout << ans << endl;
    else cout << 0 << endl;
    return 0;
}

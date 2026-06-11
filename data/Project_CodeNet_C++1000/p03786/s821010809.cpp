#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;


int main(){
    ll N; cin >> N;
    vector<ll> A(N); for(ll i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<ll> D(N); D[0] = A[0];
    for(ll i = 1; i < N; i++) D[i] = D[i-1] + A[i];

    ll ans = 1;

    for(ll i = N-2; i >= 0; i--){
        if(2*D[i] >= A[i+1]) ans++;
        else break;
    }
    cout << ans << endl;


}
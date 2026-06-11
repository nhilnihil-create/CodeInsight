#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    rep(i,N){
        cin >> X[i];
    }
    ll ans = 0;
    for (ll i = 0; i < N - 1; i++){
        ll walk = A * (X[i + 1] - X[i]);
        ll teleport = B;
        ans += min(walk, teleport);
    }
    cout << ans << endl;
}
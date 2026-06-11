#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,P;
    cin >> N >> P;
    vector<ll> A(N);
    rep(i,N){
        cin >> A[i];
    }
    ll odd = 0;
    ll even = 0;
    rep(i,N){
        if (A[i] % 2 == 0) even++;
        else odd++;
    }
    vector<ll> num(52);
    num[0] = 1;
    for (ll i = 0; i < 51; i++){
        num[i + 1] = num[i] * 2;
    }
    vector<vector<ll> > pascal(52, vector<ll> (52));
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    for (ll i = 1; i <= 51; i++){
        pascal[i][0] = 1;
        pascal[i][i] = 1;
    }
    for (ll i = 2; i <= 51; i++){
        for (ll j = 1; j < i; j++){
            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
        }
    }
    if (P == 0){
        ll ans = 0;
        ll pre = num[even];
        for (ll i = 0; i <= odd; i += 2){
            ans += (pre * pascal[odd][i]);
        }
        cout << ans << endl;
    }
    else{
        ll ans = 0;
        ll pre = num[even];
        for (ll i = 1; i <= odd; i += 2){
            ans += (pre * pascal[odd][i]);
        }
        cout << ans << endl;
    }
}
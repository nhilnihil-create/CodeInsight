#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    ll n;
    ll push=0;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    rep(i,n){
        cin >> A[i];
        cin >> B[i];
    }
    for(ll i=n-1; i>=0; i--){
        A[i] += push;
        if((A[i] % B[i]) > 0){
            push += B[i] - (A[i]%B[i]);
        }
    }
    cout << push << endl;
}
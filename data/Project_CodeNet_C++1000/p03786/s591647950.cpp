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
    rep(i,N){
        cin >> A[i];
    }
    sort(all(A));
    vector<ll> B(N);
    B[0] = A[0];
    rep(i,N - 1){
        B[i + 1] = A[i + 1] + B[i];
    }
    ll minum = 0;
    rep(i,N - 1){
        if (B[i] * 2 < A[i + 1]) minum = i + 1;
    }
    cout << N - minum << endl;
}
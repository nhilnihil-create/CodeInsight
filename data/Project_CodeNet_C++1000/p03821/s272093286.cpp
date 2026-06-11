#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }
    ll ans =0;
    for(int i=N-1;i>=0;--i){
       
        A[i] += ans;
        // cerr << A[i] << endl;
        if(A[i]%B[i] ==0){
            continue;
        }
        ans += (B[i] -A[i]%B[i]);
    }
    cout << ans << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> T(N), A(N);
    rep(i, 0, N) cin >> T[i] >> A[i];

    rep(i, 1, N){
        ll n = max((ll)((T[i-1]+T[i]-1)/T[i]), (ll)((A[i-1]+A[i]-1)/A[i]));
        T[i] *= n;
        A[i] *= n; 
    }

    cout << T[N-1] + A[N-1] << endl;
    return 0;
}
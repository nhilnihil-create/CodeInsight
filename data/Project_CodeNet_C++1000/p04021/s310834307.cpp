#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll N; cin >> N;
    vector<ll> A(N), B(N); for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) B[i] = A[i];
    sort(A.begin(), A.end());
    map<ll, int> M;
    for(int i = 0; i < N; i++) M[A[i]] = i;
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        //cout << i << " "  << M[B[i]] << endl;
        if(abs(i - M[B[i]])%2 == 1) ans++;
    }
    cout << ans/2 << endl;
    
}
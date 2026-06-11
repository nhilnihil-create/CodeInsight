#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N; cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i]; A[i]--;
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(i == A[A[i]]) ans++;
    }
    cout << ans /2 << endl;
}
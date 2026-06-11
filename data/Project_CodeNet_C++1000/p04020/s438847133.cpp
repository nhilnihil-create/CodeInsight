#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    ll N; cin >> N;
    vector<ll> A(N); 
    for(ll i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        if(i < N-1){
            ans += A[i]/2;
            A[i] %= 2;
            if(A[i] == 1 && A[i+1] != 0){
                ans++;
                A[i+1]--;
            }
        }
        else ans += A[i]/2;
    }

    
    cout << ans << endl;

}
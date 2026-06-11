#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;

 
int main(){
    ll N; cin >> N;
    vector<ll> T(N), A(N), V(N);
    for(int i = 0; i < N; i++) cin >> T[i];
    for(int i = 0; i < N; i++) cin >> A[i];
    V[0] = 1;

    if(T[N-1] != A[0]){cout << 0 << endl; return 0;}

    for(int i = 1; i < N; i++){
        if(T[i-1] != T[i]) {
            V[i] = 1;
            if(T[i] > A[i]){ cout << 0 << endl; return 0;}
        }
        else V[i] = T[i];
    }
    V[N-1] = 1;
    for(int i = N-2; i >= 0; i--){
        if(A[i+1] != A[i]) {
            V[i] = 1;
            if(A[i] > T[i]){ cout << 0 << endl; return 0;}
        }
        else { if(V[i] != 1) V[i] = min(V[i], A[i]); } 
    }
    ll ans = 1;
    for(int i = 0; i < N; i++){
        ans *= V[i];
        ans%= MOD;
    }
    cout << ans << endl;


}
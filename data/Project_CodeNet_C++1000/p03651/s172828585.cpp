#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    ll M = -1;
    rep(i,N){
        cin >> A[i];
        M = max(M,A[i]);
    }
    ll gc = A[0];
    rep(i,N-1){
        gc = __gcd(gc,A[i+1]);
    }
    if((M-K) % gc == 0 && M >= K){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

}

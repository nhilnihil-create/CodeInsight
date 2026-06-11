#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N;
    cin >> N;
    vector<ll> T(N);
    for(int i = 0; i < N; i++) cin >> T.at(i);
    vector<ll> reA(N);
    for(int i = 0; i < N; i++) cin >> reA.at(i);
    
    vector<ll> maxh(N), minh(N, 1);
    
    minh[0] = T[0]; maxh[0] = T[0];
    for (ll i = 1; i < N; i++){
        if(T[i] == T[i-1]){
            maxh[i] = T[i];
        }
        else{
            maxh[i] = T[i];
            minh[i] = T[i];
        }
    }

    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        A[i] = reA[N-i-1];
    }

    if(maxh[N-1] < A[0] || minh[N-1] > A[0]){
        printf("0\n");
        return 0;
    }
    minh[N-1] = A[0]; maxh[N-1] = A[0];
    for (ll i = 1; i < N; i++) {
        if(A[i] == A[i-1]){
            if(minh[N-i-1] > A[i]){
                printf("0\n");
                return 0;
            }
            maxh[N-i-1] = min(maxh[N-i-1], A[i]);
        }
        else{
            if(minh[N-i-1] > A[i] || maxh[N-i-1] < A[i]){
                printf("0\n");
                return 0;                
            }
            maxh[N-i-1] = A[i];
            minh[N-i-1] = A[i];
        }
    }

    ll ans = 1;
    for (ll i = 0; i < N; i++) {
        ans = ans * (maxh[i] - minh[i] + 1) % MOD;
    }
    printf("%lld\n", ans);


    

}


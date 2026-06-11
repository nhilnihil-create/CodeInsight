#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
static const ll MOD = 1e9+7;

int main(){
    int N;
    cin>>N;
    vector<ll> A(N);
    vector<ll> Acnt(N,0);
    vector<ll> Bcnt(N,0);
    for(int i=0; i<N; i++){
        cin>>A[i];
        Acnt[A[i]]++;
    }

    for(int i=N-1; i>=0; i -=2){
        if(i != 0)Bcnt[i] += 2;
        else Bcnt[i]++;
    }

    ll ans = 1;

    for(int i=0; i<N; i++){
        if(Acnt[A[i]] != Bcnt[A[i]]){
            ans = 0;
            break;
        }
    }

    if(ans == 0) cout<<ans<<endl;
    
    else{
        ans = 1;
        for(int i=0; i<(N/2); i++){
            ans *= 2;
            ans %= MOD;
        }
        cout<<ans<<endl;
    }

    return 0;
}

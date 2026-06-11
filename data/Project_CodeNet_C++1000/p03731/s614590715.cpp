#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int N; cin>>N;
    long long int T; cin>>T;
    vector<ll> t(N,0);
    ll ans=0;
    for(int i=0;i<N;i++){
        cin>>t[i];
    }
    for(int i=0;i<N-1;i++){
        if(t[i+1]-t[i]>=T){
            ans+=T;
        }
        else{
            ans+=(t[i+1]-t[i]);
        }
    }
    cout<<ans+T;
    return 0;
}
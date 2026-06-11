#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD=1000000007;

int main() {
    int N; cin>>N;
    ll C,K; cin>>C>>K;
    vector<ll> T(N,0);
    for(int i=0;i<N;i++){
        cin>>T[i];
    }
    sort(T.begin(),T.end());
    ll ans=0;
    ll count=0;
    ll saisyo=0;
    for(int i=0;i<N;i++){
        if(T[i]>saisyo+K || count==C){
            count=0;
        }
        if(count==0){
            saisyo=T[i];
            ans++;
        }
        count++;
    }
    cout<<ans;
    return 0;
}
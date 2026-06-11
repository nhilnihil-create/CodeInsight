#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007;

int main(){
    
    int N,K;cin>>N>>K;
    vector<ll> S(N),sum(N-K+1),choice(N-K+1);
    for(int i=0;i<N;i++){
        cin>>S[i];
    }
    ll a=0;
    for(int i=0;i<K;i++){
        a+=S[i];
    }
    sum[0]=max(a,0LL);
    for(int i=1;i<N-K+1;i++){
        a=a-S[i-1]+S[i-1+K];
        sum[i]=max(a,0LL);
    }
    ll b=0;
    for(int i=K;i<N;i++){
        if(S[i]>0) b+=S[i];
    }
    choice[0]=b;
    for(int i=0;i<N-K;i++){
        if(S[i]>0) b+=S[i];
        if(S[i+K]>0) b-=S[i+K];
        choice[i+1]=b;
    }
    ll ans=0;
    for(int i=0;i<N-K+1;i++){
        ll c=sum[i]+choice[i];
        ans=max(ans,c);
    }
    cout<<ans<<endl;
}

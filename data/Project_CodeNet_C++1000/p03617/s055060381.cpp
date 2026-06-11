#include<bits/stdc++.h>
using namespace std;
#define ll long long
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io
    
    ll Q, H, S, D, N;
    cin>>Q>>H>>S>>D>>N;

    ll ans=0;
    Q*=4;
    H*=2;
    ll cost=min(Q, H);
    cost=min(cost, S);//1リットル当たりの最小金額
    if(N%2==0){
        ans=min(cost*N, N/2*D);
    }else{
        ans=min(D*(N/2)+cost, cost*N);
        if(N==1) ans=cost;
    }
        cout<<ans<<endl;
    return 0;
}
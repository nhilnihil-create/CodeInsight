#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    ll N,A,B;cin>>N>>A>>B;
    vector<ll> h(N);
    REP(i, N) cin >> h[i];
    ll l=0,r=1e9;
    while(l+1<r){
        ll m=(l+r)/2;
        ll cnt=0;
        REP(i,N) if(B*m<h[i]) cnt+=(h[i]-B*m-1)/(A-B)+1;
        if(cnt<=m) r=m;
        else l=m;
    }
    cout<<r<<endl;
}

#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N;cin>>N;
    vector<int> a(N);
    REP(i, N) cin >> a[i];
    ll ans=0,P=1;
    REP(i,N){
        ll cnt=(a[i]-1)/P;
        ans+=cnt;
        a[i]-=cnt*P;
        if(cnt>=1&&a[i]==P&&P>1) a[i]--;
        P=max(P,a[i]+1LL);
    }
    cout<<ans<<endl;
}
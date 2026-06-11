#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

ll a[100001],b[100001];
int main(){
    int n;
    ll k;
    cin>>n>>k;
    rep(i,n) cin>>a[i]>>b[i];
    ll mx=0;
    rep(i,n)if((a[i]|k)==k) mx+=b[i];
    ll tmp=1;
    int cnt=0;
    while(tmp<=k){
        ll t=k&~(tmp);
        if(k==t){
            tmp<<=1;++cnt;continue;
        }
        rep(i,cnt) t|=(1<<i);
        ll sum=0;
        rep(i,n){
            if((a[i]|t)==t) sum+=b[i];
        }
        //cout<<sum<<endl;
        mx=max(mx,sum);
        tmp<<=1;++cnt;
    }
    cout<<mx<<endl;
    return 0;
}
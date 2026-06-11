#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    ll n;
    cin>>n;

    vector<ll>a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];

    ll ans=0;

    repr(i,n-1,0){
        a[i]+=ans;
        if(a[i]%b[i]!=0)ans+=b[i]-(a[i]%b[i]);
    }

    cout<<ans<<endl;

}

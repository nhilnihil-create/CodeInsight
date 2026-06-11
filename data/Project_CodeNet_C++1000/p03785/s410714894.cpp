#include <bits/stdc++.h>

using namespace std;
using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const ll inf = 1e9+7;
const ll mod = 1e9+7;

int main(){
    ll n,c,k;
    cin>>n>>c>>k;

    vector<ll>t(n);
    rep(i,n)cin>>t[i];

    sort(t.begin(),t.end());

    ll now=1,cnt=1,time=t[0];

    rep(i,n-1){
        if(t[i+1]-time>k||cnt>=c){
            now++;
            cnt=0;
            time=t[i+1];
        }
        cnt++;
    }
    cout<<now<<endl;

}

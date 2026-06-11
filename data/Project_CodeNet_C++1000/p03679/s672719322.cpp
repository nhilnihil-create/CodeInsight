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
    int x,a,b;
    cin>>x>>a>>b;

    x*=-1;

    string ans;

    if(a-b>=0)ans="delicious";
    else if(a-b>=x)ans="safe";
    else ans="dangerous";

    cout<<ans<<endl;
}

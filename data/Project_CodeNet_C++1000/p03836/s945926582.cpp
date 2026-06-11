#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;

    string ans="";
    rep(i,gy-sy) ans+="U";
    rep(i,gx-sx) ans+="R";
    rep(i,gy-sy) ans+="D";
    rep(i,gx-sx) ans+="L";
    ans+="L";
    rep(i,gy-sy+1) ans+="U";
    rep(i,gx-sx+1) ans+="R";
    ans+="D";
    ans+="R";
    rep(i,gy-sy+1) ans+="D";
    rep(i,gx-sx+1) ans+="L";
    ans+="U";

    cout<<ans<<endl;
}

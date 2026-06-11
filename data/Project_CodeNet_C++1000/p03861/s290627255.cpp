#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long int ll;
using ipair = pair<int,int>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
const int MOD=1000000007;

int main(){ 

    ll a,b,x;cin>>a>>b>>x;
    ll ans = b/x;

    if(a%x==0){
        ans = ans - a/x + 1;
    }else ans = ans - a/x;
    cout<<ans<<endl;
    return 0;
}
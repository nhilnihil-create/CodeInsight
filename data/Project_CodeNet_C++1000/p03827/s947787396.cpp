#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n;
    string s;
    cin>>n>>s;
    ll ans=0,x=0;
    rep(i,n){
        if(s[i]=='I') x++;
        else x--;
        ans=max(ans,x);
    }
    cout<<ans<<endl;
    return 0;
}
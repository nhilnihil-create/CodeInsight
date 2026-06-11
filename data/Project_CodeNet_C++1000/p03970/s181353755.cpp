#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string s,a="CODEFESTIVAL2016";
    cin>>s;
    ll ans=0;
    rep(i,16) if(s[i]!=a[i]) ans++;
    cout<<ans<<endl;
    return 0;
}
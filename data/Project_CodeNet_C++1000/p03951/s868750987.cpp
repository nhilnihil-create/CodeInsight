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
    string s,t,ans;
    cin>>n>>s>>t;
    ans = s+t;
    rep(i,n){
        if(s.substr(i,n-i) == t.substr(0,n-i)) ans = s.substr(0,i) + t;
    }
    if(s==t) ans=s;
    cout<<ans.size()<<endl;
    return 0;
}
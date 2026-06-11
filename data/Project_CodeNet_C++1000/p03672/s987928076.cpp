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
    string s; cin>>s;
    int ans=0,n=s.size();
    for(int i=1;i<n;i++){
        string tmp=s.substr(0,n-i),j=s.substr(0,(n-i)/2);
        int t=tmp.size();
        if(tmp==j+j) ans=max(ans,t);
    }
    cout<<ans<<endl;
    return 0;
}
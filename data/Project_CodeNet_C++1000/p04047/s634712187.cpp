#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n; cin>>n;
    vector<ll> a(2*n);
    rep(i,2*n) cin>>a[i];
    sort(all(a));
    ll cnt=0;
    for(int i=0;i<2*n;i+=2){
        cnt+=min(a[i],a[i+1]);
    }
    cout<<cnt<<endl;
    return 0;
}
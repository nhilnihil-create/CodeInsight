#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int n;
    ll k;
    cin>>n>>k;
    vector<pair<ll,ll>> v(n);
    rep(i,n) cin>>v[i].first>>v[i].second;
    sort(v.begin(),v.end());
    ll res=0,sum=0;
    rep(i,n) {
        sum+=v[i].second;
        if (sum>=k) {
            res=v[i].first;
            break;
        }
    }
    cout<<res<<endl;
}

#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
    ll n,c,k;
    cin>>n>>c>>k;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];
    sort(t.begin(),t.end());
    ll res=0;
    for (int i=0; i<n;) {
        ll now=t[i]+k;
        ll count=0;
        while(i<n&&now>=t[i]&&count<c) {
            i++;
            count++;
        }
        res++;
    }
    cout<<res<<endl;
}

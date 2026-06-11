#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n;
    ll k;
    cin>>n>>k;

    ll sum=0;
    vector<pair<ll,ll>> v;
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(all(v));
    rep(i,n){
        sum+=v[i].second;
        if(sum>=k){
            cout<<v[i].first<<endl;
            return 0;
        }
    }
}
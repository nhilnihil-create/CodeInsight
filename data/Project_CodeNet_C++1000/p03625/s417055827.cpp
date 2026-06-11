#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    int n; cin>>n;
    map<ll,ll> mp;
    rep(i,0,n){
        ll x; cin>>x;
        mp[x]++;
    }
    vector<ll> box;
    for(auto &i:mp){
        if(i.second>=4){
            box.push_back(i.first);
            box.push_back(i.first);
        }else if(i.second>=2){
            box.push_back(i.first);
        }
    }
    if(box.size()==0){
        cout<<0<<endl;
        return 0;
    }
    sort(all(box));
    reverse(all(box));
    cout<<box[0]*box[1]<<endl;
}
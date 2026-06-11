#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, k; cin >> n >> k;
    vector<pair<ll,ll>> a(n);
    rep(i,n){
        ll in1, in2;
        cin >> in1 >> in2;
        a[i] = make_pair(in1,in2);
    }

    sort(a.begin(),a.end());

    for(long long i = 0; i < n; i++){
        k -= a[i].second;
        if(k <= 0){
            put(a[i].first);
            return 0;
        }
    }
}
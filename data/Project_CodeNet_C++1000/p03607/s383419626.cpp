#include<bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

#pragma GCC optimize("Ofast")



using namespace std;

bool is_integer( float x ){
    return floor(x) == x;
}
bool is_integer(double x){
    return floor(x) == x;
}


int main() {

    int n; cin >> n;
    vector<ll> a(n);
    vector<pair<ll,ll>> m;
    int p = 0;
    int ans = 0;

    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());

    rep(i,n){
        if(m.empty()) m.push_back(make_pair(a[i],1));
        else if(a[i] == m[p].first) m[p].second ++;
        else{
            m.push_back(make_pair(a[i],1));
            p ++;
        }
    }

    rep(i,m.size()){
        if(m[i].second%2 == 1) ans ++;
    }
    cout << ans;

    return 0;
}










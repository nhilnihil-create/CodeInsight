#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    ll l;
    l=s.size();
    ll t;

    vector <ll> al(26,0);
    rep(i,l){
        t=s[i];
        ++al[t-97];
    }
    ll ans=0;
    rep(i,26){
        //cout << ans << endl;
        ans+=al[i]*(al[i]-1)/2;
    }

    cout << l*(l-1)/2-ans+1 << endl;
    

    return 0;
}
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N,K;
    cin >> N >> K;
    map<ll,ll> mp;
    vector<ll> v;
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        if(mp.count(a)){
            mp[a] += b;
        }else{
            mp.emplace(a,b);
            v.push_back(a);
        }
    }
    sort(v.begin(),v.end());
    ll M = v.size();
    ll out = 0;
    ll sum = 0;
    rep(i,M){
        sum += mp[v[i]];
        if(sum>=K){
            out = v[i];
            break;
        }
    }
    cout << out << endl;
    return 0;
}

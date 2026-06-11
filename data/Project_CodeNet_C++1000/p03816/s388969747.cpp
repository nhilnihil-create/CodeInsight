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
#include <queue>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {

    ll N;
    cin >> N;
    vector<ll> v;
    map<ll,ll> mp;
    rep(i,N){
        ll A;
        cin >> A;
        if(mp.count(A)) mp[A]++;
        else{
            mp.emplace(A,1);
            v.push_back(A);
        }
    }
    ll ex = 0;
    rep(i,v.size()){
        ex += mp[v[i]]-1;
    }
    if(ex%2==1) ex++;
    ll out = N-ex;
    cout << out << endl;
    return 0;
}

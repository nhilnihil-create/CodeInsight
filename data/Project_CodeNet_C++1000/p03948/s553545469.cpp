#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, T; cin >> N >> T;

    map<ll, ll> mp;

    ll mn = INF;
    ll mx = -1;

    for(ll i = 0; i < N; i++){
        ll a; cin >> a;
        if(mn > a){
            mn = a;
        }
        if(mx < a-mn){
            mx = a-mn;
        }
        mp[a-mn]++;
    }


    cout << mp[mx] << endl;

}
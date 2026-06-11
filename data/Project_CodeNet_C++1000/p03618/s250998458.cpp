#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
typedef long long ll;

int main(){
    string A; cin >> A;
    ll N = A.size();
    ll ans = 0;

    map<char, ll> mp;
    rep(i, 0, N){
        mp[A[i]]++;
    }
    ll sub = 0;
    for(auto e: mp){
        sub += e.second * (e.second - 1) / 2;
    }
    ans = 1 + N * ( N - 1) / 2 - sub;
    cout << ans << endl;

}
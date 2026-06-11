#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    ll n = s.size();
    map<char,ll> mp;
    for(int i = 0; i < n; i++){
        mp[s[i]]++;
    }
    ans = n*(n-1)/2;
    for(auto p:mp){
        ans -= p.second*(p.second-1)/2;
    }
    ans++;
    cout << ans << endl;
}
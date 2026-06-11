#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    string s; cin>>s;
    ll N = s.size();
    map<char, ll> mp;
    for(char c:s){
        ++mp[c];
    }
    
    ll num = 0;
    for(char c='a';c<='z';++c){
        num += mp[c]*(mp[c]-1)/2;
    }
    
    ll ans = N*(N-1)/2 -num + 1;
    cout << ans << "\n";
    
}

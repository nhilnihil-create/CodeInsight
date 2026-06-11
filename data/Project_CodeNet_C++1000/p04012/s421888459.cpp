#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    string s;cin >>s;
    unordered_map<char,int>mp;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
    }
    bool flg=true;
    for(auto p:mp){
        if(p.second%2)flg=false;
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}

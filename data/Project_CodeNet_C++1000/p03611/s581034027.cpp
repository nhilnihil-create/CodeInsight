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
    ll n;cin >>n;
    map<ll,int>mp;
    for (int i = 0; i < n; ++i) {
        ll a;cin >>a;
        mp[a-1]++;
        mp[a]++;
        mp[a+1]++;
    }
    ll mx=0;
    for(auto u:mp){
        if(mx<u.second){
           mx=u.second;
        }
    }
    cout <<mx<<endl;
    return 0;
}
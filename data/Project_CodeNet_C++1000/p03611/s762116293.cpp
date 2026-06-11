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
    vector<ll>a(n);
    map<ll,int>mp;
    int ans=0;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        mp[a[i]]++;
        mp[a[i]-1]++;
        mp[a[i]+1]++;
    }
    for(auto e:mp){
        ans=max(ans,e.second);
    }
    cout <<ans <<endl;
    return 0;
}
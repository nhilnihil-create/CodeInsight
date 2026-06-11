//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;
ll INF=1e10;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    map<ll,ll>mp;
    rep(i,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    ll cnt=0;
    for(auto p:mp){
        cnt++;
    }
    if(cnt%2!=0)cout<<cnt<<endl;
    else cout<<cnt-1<<endl;
}




























































































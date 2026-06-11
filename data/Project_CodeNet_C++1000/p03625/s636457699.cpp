#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793

ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main (){
    int n;
    ll mx1=0;
    ll mx2=0;
    cin >> n;
    map<ll,ll>mp;
    rep(i,n){
        ll a;
        cin >> a;
        mp[a]++;
    }
    vector<pair<ll,ll>>hen(mp.size());
    int i=0;
    for(auto p:mp){
        hen[i]=make_pair(p.first,p.second);
        i++;
    }
    reverse(hen.begin(),hen.end());
    rep(i,mp.size()){
        if(hen[i].second>1) {
            mx1=hen[i].first;
            hen[i].second-=2;
            break;
        }
    }
    rep(i,mp.size()){
        if(hen[i].second>1){
            mx2=hen[i].first;
            break;
        }
    }
    cout << mx1*mx2 <<endl;
    return 0;
}


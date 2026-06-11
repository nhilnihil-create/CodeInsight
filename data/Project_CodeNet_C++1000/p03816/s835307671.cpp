#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main(){
    ll N;
    cin>>N;
    map <ll,ll> _mp;
    for(auto i=0;i<N;i++){
        ll a;cin>>a;
        _mp[a]++;
    }
    map<ll,ll> mp;
    ll cnt=0;
    ll s=0;
    for(auto p:_mp){
        s++;
        if(p.second>1){
            if(p.second%2==1){
                mp[p.first]=1;
            }else{
                mp[p.first]=2;
                cnt++;
            }
        }else{
            mp[p.first] = p.second;
        }
    }
    if(cnt%2==0){
        cout<<s<<endl;
    }else{
        cout<<s-1<<endl;
    }
    
}
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;
    map<ll,ll> abmap;
    
    for(ll i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        abmap[a]+=b;
    }
    ll sum=0;
    for(const auto& item:abmap){
        sum+=item.second;
        if(sum>=k){
            cout<<item.first<<endl;
            return 0;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;


int main(){
    ll K;
    cin >> K;
    ll t=K%50;
    ll s=K/50;
    cout<<50<<endl;
    for(ll i=0;i<t;i++){
        cout<<100+s-t<<" "
    ;}
    for(ll i=0;i<50-t;i++){
        cout<<49+s-t<<" "
    ;}cout<<endl;
    return 0;
}

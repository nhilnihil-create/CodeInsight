#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

const ll mod=1000000007ll;

const ll hmax=1000000000;
const ll wmax=1000000000;

unordered_map<string,ll> mp;

int main(){
    ll h,w,n,a,b;
    cin>>h>>w>>n;
    string s;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        for(ll j=-1;j<=1;j++){
            for(ll k=-1;k<=1;k++){
                if(2<=a+j&&a+j<=h-1&&2<=b+k&&b+k<=w-1){
                    s=to_string(a+j)+" "+to_string(b+k);
                    mp[s]++;
                }
            }
        }
    }
    ll ct[10],tmp;
    ll su=0;
    for(ll i=1;i<=9;i++){
        tmp=0;
        for(auto itr = mp.begin(); itr != mp.end(); ++itr){
            //cout<<itr->first<<","<<mp[itr->first]<<endl;
            if(itr->second==i){
                tmp++;
            }
        }
        su+=tmp;
        ct[i]=tmp;
    }
    ct[0]=(h-2)*(w-2)-su;

    for(ll i=0;i<10;i++){
        cout<<ct[i]<<endl;
    }
    return 0;
}

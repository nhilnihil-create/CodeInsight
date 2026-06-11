#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007; 

long pow_mod(long a,long n,long mod){
    long res=1;
    while(n>0){
        if(n&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        n=(n>>1);
    }
    return res;
}
int main(){   
    ll N;
    cin>>N;
    bool flag = true;
    map<ll,ll> mp;
    for(ll i=0;i<N;i++){
        ll a;
        cin>>a;
        mp[a]++;
    }
    
    if(N%2==0){
        for(long i=0;i<N;i++){
            if(i%2==1&&mp[i]!=2){
                flag = false;
            }
            else if(i%2==0&&mp[i]>0){
                flag=false;
            }
        }
    }else{
        for(long i=0;i<N;i++){
            if(i==0&&mp[i]!=1){
                // cout<<i<<":"<<mp[i]<<endl;
                flag=false;
            }else if(i!=0&&i%2==0&&mp[i]!=2){
                // cout<<i<<":"<<mp[i]<<endl;
                // cout<<"AAA"<<endl;
                flag = false;
            }else if(i%2==1&&mp[i]>0){
                // cout<<i<<":"<<mp[i]<<endl;
                flag = false;
            }
        }
    }
    // cout<<flag<<endl;
    cout<<(flag?pow_mod(2,N/2,MOD):0)<<endl;
}

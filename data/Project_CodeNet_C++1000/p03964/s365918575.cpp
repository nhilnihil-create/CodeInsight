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
using plong = pair<long,long>;



int main(){   
    ll N;
    cin>>N;
    ll T[N],A[N];
    for(ll i=0;i<N;i++){
        cin>>T[i]>>A[i];
    }
    for(ll i=1;i<N;i++){
        // for(ll j=1;;j++){
        //     if(T[i]*j>=T[i-1]&&A[i]*j>=A[i-1]){
        //         T[i] *= j;
        //         A[i] *= j;
        //         break;
        //     }
        // }
        ll mul = max((T[i-1]+T[i]-1)/T[i],(A[i-1]+A[i]-1)/A[i]);
        T[i] *= mul;
        A[i] *= mul;
    }
    // for(ll i=0;i<N;i++){
    //     cout<<T[i]<<":"<<A[i]<<endl;
    // }
    cout<<T[N-1]+A[N-1]<<endl;

}
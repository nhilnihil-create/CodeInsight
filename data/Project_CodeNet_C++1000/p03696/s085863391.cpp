#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <queue>
#include <iomanip>
#include <set>
//#include <bits/stdc++.h>

template<typename T> bool chmax(T &a,T b){
    if(a<b){
        a=b;
        return true;
    }
    return false;
}

template<typename T> bool chmin(T &a,T b){
    if(a>b){
        a=b;
        return true;
    }
    return false;
}

using namespace std;
#define ALL(X) X.begin(),X.end()
using ll = long long int;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
const int MOD=1000000007;
//const int MOD=998244353;
const int INTMAX=2147483647;
const ll LLMAX=9223372036854775807;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll N;
    cin>>N;
    string S;
    cin>>S;
    
    ll addleft=0;
    ll stoch=0;//(
    for(ll i=0;i<N;i++){
        if(S[i]=='('){
            stoch++;
        }else{
            if(stoch>0)stoch--;
            else addleft++;
        }
    }
    
    for(ll i=0;i<addleft;i++)printf("(");
    printf("%s",S.c_str());
    for(ll i=0;i<stoch;i++)printf(")");
    printf("\n");
    
    return 0;
}

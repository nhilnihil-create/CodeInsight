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
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
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
    
    ll N,M;
    cin>>N>>M;
    vll x(M),y(M);
    for(ll i=0;i<M;i++){
        cin>>x[i]>>y[i];
        x[i]--;y[i]--;
    }
    
    vector<bool> ans(N,false);
    ans[0]=true;
    vll count(N,1);
    for(ll i=0;i<M;i++){
        if(ans[x[i]])ans[y[i]]=true;
        count[x[i]]--;count[y[i]]++;
        if(count[x[i]]==0)ans[x[i]]=false;
    }
    
    ll ansN=0;
    for(ll i=0;i<N;i++){
        if(ans[i] && count[i]>0)ansN++;
    }
    cout<<ansN<<endl;
    
    return 0;
}

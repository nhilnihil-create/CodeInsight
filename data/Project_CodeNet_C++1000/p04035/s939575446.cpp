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
    
    ll N,L;
    cin>>N>>L;
    vll a(N);
    for(ll i=0;i<N;i++)cin>>a[i];
    
    ll index=-1;
    for(ll i=0;i<N-1;i++){
        if(a[i]+a[i+1]>=L){
            index=i;
            break;
        }
    }
    
    if(index==-1){
        cout<<"Impossible"<<endl;
    }else{
        cout<<"Possible"<<endl;
        for(ll i=0;i<index;i++)cout<<i+1<<endl;
        for(ll i=N-2;i>index;i--)cout<<i+1<<endl;
        cout<<index+1<<endl;
    }
    
    return 0;
}

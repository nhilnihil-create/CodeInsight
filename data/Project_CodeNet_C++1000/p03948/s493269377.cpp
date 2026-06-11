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
const ll inf=1000000000000000ll;

const ll nmax=100000;
ll a[nmax];

unordered_map<string,ll> mp;

int main(){
    ll n,t;
    cin>>n>>t;
    for(ll i=0;i<n;i++) cin>>a[i];

    ll ct=0;
    ll mn=0;
    ll mina=a[0];
    for(ll i=0;i<n;i++){
        if((a[i]-mina)==mn){
            ct++;
        }

        if(a[i]-mina>mn){
            ct=1;
            mn=a[i]-mina;
        }

        if(a[i]<mina) mina=a[i];
    }
    cout<<ct<<endl;
    return 0;
}

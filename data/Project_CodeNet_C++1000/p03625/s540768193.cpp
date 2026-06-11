#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define _GLIBCXX_DEBUG
#define ll long long
#define rep(i,n) for (ll i = 0; i < n; i++)
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define vvl vector<vector<ll>> //a(縦行,vector<ll>(横列));
#include<algorithm>//__gcd(a,b)
#include <iostream>
#include <vector>
#include <cstdlib>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

int main(){
    ll n;cin>>n;
    vl a(n);rep(i,n)cin>>a[i];
    ll fi=0;ll se=0;
    
    sort(a.begin(),a.end());

    rep(i,n){
        if(a[i]==a[i+1]){
            i++;
            swap(fi,se);
            fi=a[i];
        }
    }

cout<<fi*se<<endl;
}
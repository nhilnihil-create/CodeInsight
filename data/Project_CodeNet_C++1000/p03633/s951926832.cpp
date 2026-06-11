
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){

    int n;
    cin >> n;

    ll lcd = 1;

    ll t[n];

    REP(i,n){
        cin >> t[i];

        ll g = gcd(lcd,t[i]);

        lcd = lcd/g*t[i];
    }

    cout << lcd << endl;
    return 0;
}

#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

ll facto(ll n){
    ll res=1;
    rep(i,n){
        res*=(i+1);
        res%=inf;
    }
    return res;
}

int main(){
    ll n,m;cin>>n>>m;
    if(n==m)cout<<((2*((facto(n)*facto(m))%inf))%inf)<<endl;
    else if(abs(n-m)==1)cout<<((facto(n)*facto(m))%inf)<<endl;
    else cout<<0<<endl;
}
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
#define rep2(i,s,n) for(ll i=(s);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

map<ll,ll> prime;

void factorization(ll x){
    for(ll i=2;i*i<=x;i++){
        while(x%i==0){
            prime[i]++;
            x/=i;
        }
    }
    if(x!=1)prime[x]++;
    return;
}

int main(){
    ll n;cin>>n;
    rep2(i,2,n+1)factorization(i);
    ll ans=1;
    rep2(i,2,n+1){
        if(prime.count(i)){
            ans*=(prime[i]+1)%inf;
            ans%=inf;
        }
    }
    cout<<ans<<endl;
}
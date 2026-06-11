#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n;cin>>n;
    vector<ll>a(n,0);
    string s;cin >>s;
    for (int i = 0; i < n; ++i) {
        if(s[i]=='(')a[i]++;
        else a[i]--;
    }
    vector<ll>sum(n+1,0);
    for (int i = 0; i < n; ++i) {
        sum[i+1]=sum[i]+a[i];
    }
    string ans="";
    ll mint=0;
    for (int i = 0; i < n+1; ++i) {
        mint=min(mint,sum[i]);
    }
    mint*=-1;
    for (int i = 0; i <mint; ++i) {
        ans+='(';
    }
    ans+=s;
    ll d=sum[n]+mint;
    if(d>0){
        for (int i = 0; i <d; ++i) {
            ans+=')';
        }
    }
    cout <<ans <<endl;
    return 0;
}
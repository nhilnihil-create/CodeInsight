#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

ll powll(ll n,ll x){
    ll a=1;
    rep(i,x) a*=n;
    return a; 
}

int main(){
    string a;
    cin>>a;
    ll n=a.size();
    ll count=0;
    vvll d(26);
    vll num(n*2-2,0);
    rep(i,n) d[a[i]-'a'].push_back(i);
    rep(i,26){
        count-=(d[i].size()-1)*d[i].size()/2;
    }
    ll beki=0;
    repi(i,1,n*2-2){
        if(i%2==0){
            if(n<i) beki=n-1-i/2;
            else beki=i/2; 
        }else{
            if(n<i) beki=n-1-i/2;
            else beki=i/2+1;
        }
        count+=beki;
    }
    if(count==0) count++;
    if(a.size()==2&&a[0]!=a[1]) count=2;
    cout<<count<<endl;
}

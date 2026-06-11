#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    ll n,x;
    cin>>n>>x;
    vll a(n);
    rep(i,n) cin>>a[i];
    ll ans=0;
    rep(i,n){
        if(a[i]>x){
            ans+=a[i]-x;
            a[i]-=a[i]-x;
        }
        
    }
    
    rep(i,n-1){
        ll bet=a[i]+a[i+1];
        if(bet>x){
            ans+=bet-x;
            a[i+1]-=(bet-x);
        }
        
    
    
    }
   
    cout<<ans<<endl;
}

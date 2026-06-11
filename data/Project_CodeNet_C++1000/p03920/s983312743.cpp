#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define i_7 (ll)(1E9+7)
#define i_5 (ll)(1E9+5)
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    else return c+i_7;
}
typedef pair<int,int> i_i;
typedef pair<ll,ll> l_l;
ll inf=(ll)1E12;//10^12
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
const double EPS=1E-8;
////////////////////////////////////////

void calc(int n){
    int m=1;
    while(1){
        if(m*(m+1)/2>=n)break;
        m++;
    }
    int k=m*(m+1)/2-n;
    rep(i,1,m){
        if(i!=k)cout<<i<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    
    int n;cin>>n;
    calc(n);
    
    
    return 0;
}
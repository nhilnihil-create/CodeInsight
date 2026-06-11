#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)
using Graph = vector<vector<int>>;
using pint = pair<int,int>;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int main(){
    ll n,l;cin>>n>>l;
    ll a[n];
    rep(i,n) cin>>a[i];
    ll m=0,x;
    rep(i,n-1){
        m=max(a[i]+a[i+1],m);
        if(a[i]+a[i+1]>=l){
            x=i+1;
            break;
        }
    }
    if(m<l) {
        cout<<"Impossible"<<"\n";
    }
    else{
        cout<<"Possible"<<"\n";
        for(int i=1;i<x;i++) cout<<i<<"\n";
        for(int i=n-1;i>=x;i--) cout<<i<<"\n";
    }
}
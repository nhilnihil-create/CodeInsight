#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll n,l;cin>>n>>l;
    ll a[100010];
    rep(i,0,n)cin>>a[i];
    ll last=-1;
    rep(i,0,n-1){
        if(a[i]+a[i+1]>=l){
            last=i;
            break;
        }
    }
    if(last==-1)cout<<"Impossible"<<endl;
    else{
        cout<<"Possible"<<endl;
        rep(i,0,last)cout<<i+1<<endl;
        for(ll i=n-2;i>=last;i--)cout<<i+1<<endl;
    }
}

    








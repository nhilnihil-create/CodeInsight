#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;

int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll cnt=0;
    rep(i,n-1){
        if(a[i]+a[i+1]>x){
            if(a[i]<=x){
                cnt+=a[i+1]-(x-a[i]);
                a[i+1]=x-a[i];
            }else{
                cnt+=a[i+1]+(a[i]-x);
                a[i+1]=0;
                a[i]=x;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n,x;
    cin >> n >> x;
    vector <ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    ll ans=0;

    rep(i,n){
        if(i==0){
            if(a[0]>x){
                ans+=a[0]-x;
                a[0]=x;
            }
        }
        else{
            if((a[i]+a[i-1])>x){
                ans+=a[i]+a[i-1]-x;
                a[i]-=(a[i]+a[i-1]-x);
            }
        }
    }

    cout << ans << endl;
    

    return 0;
}
#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n);
    rep(i,n){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    ll s=0,ans=-1;

    rep(i,n-1){
        s+=a[i];
        if(2*s<a[i+1]){
            ans=i;
        }
    }

    cout << n-ans-1 << endl;

    

    return 0;
}
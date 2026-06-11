#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    ll ans=0;
    int amari=0;
    ll a;

    rep(i,n){
        cin >> a;
        if(a==0){
            amari=0;
            continue;
        }
        else{
            a+=amari;
            ans+=a/2;
            if(a%2==1){
                amari=1;
            }
            else{
                amari=0;
            }
        }
    }

    cout << ans << endl;
    

    return 0;
}
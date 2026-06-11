#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define rep(i,n) for(int i = 0 ; i < n ;i++)

int end(){
    cout << 0 << endl;
    return 0 ;
}

ll const mod = 1e9+7 ;

int main(){
    int n ;
    cin >> n ;
    ll ans = 1 ;
    map<int,int> mp ;
    rep(i,n){
        int a ;
        cin >> a ;
        mp[a]++ ;
    }
    if(n%2 == 1){
        if(mp[0]!=1){ end(); return 0 ;}
        rep(i,n/2) if(mp[2*(i+1)]!=2){ end(); return 0 ;}
        rep(i,n/2){
            ans = 2*ans%mod ;
        }
        cout << ans << endl;
    }
        if(n%2 == 0){
        if(mp[0]!=0){ end(); return 0 ;}
        rep(i,n/2)if(mp[2*i+1]!=2){ end(); return 0 ;}
        rep(i,n/2){
            ans = 2*ans%mod ;
        }
        cout << ans << endl;
    }
}
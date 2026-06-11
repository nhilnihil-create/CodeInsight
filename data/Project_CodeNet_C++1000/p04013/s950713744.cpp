#include<iostream>
#include<vector>
using namespace std ;

int main(){
    using ll = long long ;
    using vll = vector<ll> ;
    ll n ; cin >> n ;
    ll a ; cin >> a ;
    vll x(n+1) ;
    for(int i=0;i<n;i++) cin >> x.at(i+1) ;
    vector<vector<vll>> dp(n+1,vector<vll>(n+1,vll(2600,0))) ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1){
                dp.at(i).at(1).at(x.at(i)) = 1 ;
            }
            for(int k=1;k<2600;k++){
                if(k<x.at(i)){
                    dp.at(i).at(j).at(k) += dp.at(i-1).at(j).at(k) ;
                }else{
                    dp.at(i).at(j).at(k) += dp.at(i-1).at(j-1).at(k-x.at(i))+dp.at(i-1).at(j).at(k) ;
                }
            }
        }
    }
    ll ans = 0 ;
    for(int i=1;i<=n;i++){
        ans += dp.at(n).at(i).at(a*i) ;
    }
    cout << ans << endl ;
}
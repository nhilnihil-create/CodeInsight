#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)

int main(){
    int n;
    cin >> n;
    ll t[n],mx = 0;
    rep(i,n)cin >> t[i];
    
    sort(t,t+n,greater<ll>());
    mx = t[0];
    for(ll i = 1;i < n;i++){
        if(mx % t[i] == 0)continue;
        
        for(ll j = 1;j <= t[i];j++){
            if(j * mx % t[i] == 0){
                mx *= j;
                break;
            }
        }
    }
    
    cout << mx << endl;
}

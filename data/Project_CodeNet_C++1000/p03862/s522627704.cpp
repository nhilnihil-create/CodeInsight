#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N , x;
    cin >> N >> x;
    ll sum = 0;
    ll ans = 0;
    vector<ll> a(N,0);
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] > x){
            ans += a[i] - x;
            a[i] = x;
        } 
    } 
    
    for(int i = 0; i < N - 1; i++){
        if(a[i] + a[i + 1] > x){
            ll tmp = a[i + 1];
            a[i + 1] = x - a[i];
            ans += tmp - a[i + 1];
        }
    }


    cout << ans << endl;

}


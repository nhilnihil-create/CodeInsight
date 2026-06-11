#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll t = a[i] / 2;
        ans += t;
        a[i] -= t * 2;
        if(a[i] != 0 && i != n - 1){
            if(a[i + 1] != 0){
                ans++;
                a[i] = 0;
                a[i + 1]--;
            }
        }
    }
    
    cout << ans << endl;
}
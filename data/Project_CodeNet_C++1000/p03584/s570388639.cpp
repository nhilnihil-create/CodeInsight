#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<ll> b(n);
    for(int i=0;i<n;i++) cin >> a[i] >> b[i];

    ll ans = 0;
    for(int i=0;i<n;i++){
        if((k|a[i]) == k){
            ans += b[i];
        }
    }
    for(int i=1;i<31;i++){
        if((k>>i)&1){
            int S = (k^(1<<i)) | ((1<<i)-1);
            ll sum = 0;
            for(int j=0;j<n;j++){
                if((S|a[j]) == S){
                    sum += b[j];
                }
            }
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}
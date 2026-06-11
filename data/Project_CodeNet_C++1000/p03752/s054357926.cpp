#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;
    ll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = 100000000000;

    for(int bit = 0; bit < (1 << n-1); bit++){
        ll d = 0;
        ll b[n];
        for(int i = 0; i < n; i++){
            b[i] = a[i];
        }
        vector<int> bit_iter(n, 0);
        int bit_cnt = 0;
        for(int j = 0; j < n-1; j++){
            if(bit & (1 << j)){
                bit_iter[j+1] = 1;
                bit_cnt++;
            }
        }
        if(bit_cnt != k-1){
            continue;
        }
        ll max_b = b[0];
        for(int j = 0; j < n-1; j++){
            max_b = max(max_b, b[j]);
            if(bit_iter[j+1] == 1 && max_b >= b[j+1]){
                b[j+1] = max_b + 1;
            }
        }
        for(int i = 0; i < n; i++){
            d += b[i] - a[i];
        }
        ans = min(ans, d);
    }
    cout << ans << endl;
}
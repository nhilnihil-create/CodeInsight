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

    sort(a, a + n);

    ll sum[n];
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i - 1] + a[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i != n - 1){
            if(sum[i] * 2 >= a[i + 1]){
                ans++;
            }else{
                ans = 0;
            }
        }else{
            ans++;
        }
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll arr[8] = {0};
    ll free = 0;
    rep(i, n){
        cin >> a[i];
        if (a[i] < 400){
            arr[0] = 1;
        }else if(a[i] < 800){
            arr[1] = 1;
        }else if(a[i] < 1200){
            arr[2] = 1;
        }else if(a[i] < 1600){
            arr[3] = 1;
        }else if(a[i] < 2000){
            arr[4] = 1;
        }else if(a[i] < 2400){
            arr[5] = 1;
        }else if(a[i] < 2800){
            arr[6] = 1;
        }else if(a[i] < 3200){
            arr[7] = 1;
        }else {
            free++;
        }
    }
    ll sum = 0;
    rep(i, 8){
        sum+=arr[i];
    }
    if (sum == 0){
        cout << 1 << " " << free << endl;
    }else{
        cout << sum << " " << sum+free << endl;
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, t, a[100005], ans;

signed main()
{
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = a[0], cost = 0;
    for(int i = 0; i < n; i++){
        if(l > a[i]){
            l = a[i];
            continue;
        }
        cost = max(cost, a[i] - l);
    }
    l = a[0];
    for(int i = 0; i < n; i++){
        if(l > a[i]){
            l = a[i];
            continue;
        }
        if(cost == a[i] - l){
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

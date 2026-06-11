#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1e+18;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    ll ans = INF;
    ll sum = 0;
    ll cnt = 0;
    // S_odd > 0, S_even < 0
    for(int i = 1; i <= n; i++){
        sum += a[i-1];
        if(i % 2 && sum <= 0){
            cnt += -sum + 1;
            sum = 1;
        } else if(i % 2 == 0 && sum > 0){
            cnt += sum + 1;
            sum = -1;
        }
    }
    ans = min(ans, cnt);

    sum = cnt = 0;
    // S_odd < 0, S_even > 0
    for(int i = 1; i <= n; i++){
        sum += a[i-1];
        if(i % 2 && sum >= 0){
            cnt += sum + 1;
            sum = -1;
        } else if(i % 2 == 0 && sum <= 0){
            cnt += -sum + 1;
            sum = 1;
        }
    }
    ans = min(ans, cnt);

    cout << ans << endl;
    return 0;
}
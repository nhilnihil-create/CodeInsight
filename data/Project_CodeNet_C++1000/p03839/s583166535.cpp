#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(ll i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()

int main(void){
    ll n, k;
    cin >> n >> k;

    ll a[n];
    rep(i, 0, n){
        cin >> a[i];
    }

    ll sum[n + 1];
    ll sum_p[n + 1];
    sum[0] = 0;
    sum_p[0] = 0;
    rep(i, 1, n + 1){
        sum[i] = sum[i - 1] + a[i - 1];
        sum_p[i] = sum_p[i - 1];
        if(a[i - 1] >= 0){
            sum_p[i] += a[i - 1];
        }
    }

    ll ans = 0;
    rep(i, 0, n - k + 1){
        ans = max(sum_p[n] - (sum_p[i + k] - sum_p[i]), ans);
        ans = max(sum_p[n] - (sum_p[i + k] - sum_p[i]) + (sum[i + k] - sum[i]), ans);
    }

    cout << ans << endl;
    return 0;
}

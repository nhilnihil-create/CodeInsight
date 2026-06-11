#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, k;
vector <int> a;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    a.resize(n);
    for(auto &i : a) cin >> i;
    ll cur = 0;
    for(int i = k ; i < n ; i++){
        cur += max(0, a[i]);
    }
    ll sum = 0;
    for(int i = 0 ; i < k ; i++){
        sum += a[i];
    }
    ll ans = cur + max(0LL, sum);
    for(int i = k ; i < n ; i++){
        cur -= max(0, a[i]);
        cur += max(0, a[i - k]);
        sum += a[i];
        sum -= a[i - k];
        ans = max(ans, cur + max(0LL, sum));
    }
    cout << ans << endl;
}

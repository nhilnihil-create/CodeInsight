#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[100005];
    ll maxsum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > 0) maxsum += a[i];
    }
    ll psum = 0;
    ll nsum = 0;
    for(int i = 0; i < k; i++){
        if(a[i] > 0) psum += a[i];
        else nsum -= a[i];
    }
    ll ans = 0;
    for(int i = k; i <= n; i++){
        ans = max(ans, maxsum - min(psum, nsum));
        if(a[i] > 0) psum += a[i];
        else nsum -= a[i];
        if(a[i - k] > 0) psum -= a[i - k];
        else nsum += a[i - k];
    }
    cout << ans << endl;
}
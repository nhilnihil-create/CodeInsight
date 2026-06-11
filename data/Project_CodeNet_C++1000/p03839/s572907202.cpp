#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 100005;
const int mod = 1e9 + 7;
ll a[maxn];
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    ll sum = 0;
    for (int i = 1 ; i <= n ; i++) {
        cin >> a[i];
        if (a[i] > 0) {
            sum += a[i];
        }
    }
    ll tmp = 0, ans = 0;
    for (int i = 1 ; i <= k ; i++) {
        tmp += a[i];
        if (a[i] > 0) {
            sum -= a[i];
        }
    }
    ans = max(ans, max(tmp + sum, sum));
    for (int i = 2 ; i <= n - k + 1 ; i++) {
        tmp -= a[i - 1];
        tmp += a[k + i - 1];
        if (a[i - 1] > 0) {
            sum += a[i - 1];
        }
        if (a[i + k - 1] > 0) {
            sum -= a[i + k - 1];
        }
        ans = max(ans, max(tmp + sum, sum));
    }
    cout << ans << '\n';
}
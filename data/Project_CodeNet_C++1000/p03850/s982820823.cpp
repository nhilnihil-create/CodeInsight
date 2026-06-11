#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

int n;
ll a[100000];
char c[100000];

int main() {
    cin >> n;
    rep(i,n) {
        if (i == 0) cin >> a[i];
        else cin >> c[i-1] >> a[i];
    }
    ll ans = 0;
    bool head = true;
    ll sum = 0;
    ll mcnt = INF*INF;
    ll pm = 0;
    rep(i,n) sum += a[i];
    rep(i,n-1) {
        if (c[i] == '+') {
            mcnt += a[i+1];
        } else {
            if (!head) ans = max(ans, sum-mcnt*2);
            head = false;
            mcnt = a[i+1];
            sum -= pm*2;
            pm = a[i+1];
        }
    }
    if (head) ans = sum;
    cout << max(ans, sum-mcnt*2) << endl;
}


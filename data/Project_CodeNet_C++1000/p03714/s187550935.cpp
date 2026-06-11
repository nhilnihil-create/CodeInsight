#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const ll oo = 1e15 + 7;
const int mod = 1e9 + 7, maxn = (2 * 1e3) + 10;
const long double PI = acos(-1);

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, sa = 0, sb = 0;
    cin >> n;

    vector<ll> v(3*n), memo(3*n);
    priority_queue<ll> a, b;

    for (int i=0; i<3*n; i++){
        cin >> v[i];
        if (i<2*n){
            sa+=v[i];
            a.push(-v[i]);
            if ((int)a.size() > n){
                sa += a.top();
                a.pop();
            }
            memo[i] = sa;
        }
    }

    ll ans = -oo;

    for (int i=3*n-1; i>=n; i--){
        sb += v[i];
        b.push(v[i]);
        if ((int)b.size() > n) {
            sb-=b.top();
            b.pop();
        }
        if (i<=2*n) ans = max(ans, memo[i-1] - sb);
    }

    cout << ans << endl;
    return 0;
}
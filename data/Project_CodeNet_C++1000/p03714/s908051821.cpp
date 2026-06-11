#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll a[3 * n];
    REP(i,3 * n){
        cin >> a[i];
    }
    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> lque;
    for(int i = 0; i < n; i++){
        lque.emplace(a[i]);
        sum += a[i];
    }
    ll lsum[n + 1];
    lsum[0] = sum;
    for(int i = 0; i < n; i++){
        if(lque.top() < a[n + i]){
            sum += a[n + i] - lque.top();
            lque.pop();
            lque.push(a[n + i]);
        }
        lsum[i + 1] = sum;
    }
    sum = 0;
    priority_queue<ll> rque;
    for(int i = 2 * n; i < 3 * n; i++){
        rque.emplace(a[i]);
        sum += a[i];
    }
    ll rsum[n + 1];
    rsum[n] = sum;
    for(int i = n - 1; i >= 0; i--){
        if(rque.top() > a[n + i]){
            sum += a[n + i] - rque.top();
            rque.pop();
            rque.push(a[n + i]);
        }
        rsum[i] = sum;
    }
    ll ans = -LINF;
    for(int i = 0; i <= n; i++){
        ans = max(ans, lsum[i] - rsum[i]);
    }
    cout << ans << endl;
    return 0;
}
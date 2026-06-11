#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    ll n;
    cin >> n;
    ll sum = 0;
    ll a[n];
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % (n * (n + 1) / 2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    ll d[n];
    ll k = sum / (n * (n + 1) / 2);
    for(int i = 0; i < n; i++){
        d[i] = a[(i + 1) % n] - a[i] - k;
    }
    sum = 0;
    for(int i = 0; i < n; i++){
        if(d[i] % n != 0 || d[i] > 0){
            cout << "NO" << endl;
            return 0;
        }
        sum -= d[i];
    }
    cout << (sum / n == k ? "YES" : "NO") << endl;
    return 0;
}
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
    ll cnt = 0;
    ll k = sum / (n * (n + 1) / 2);
    for(int i = 0; i < n; i++){
        ll d = a[(i + 1) % n] - a[i];
        if((k - d) % n != 0 || k < d){
            cout << "NO" << endl;
            return 0;
        }
        cnt += (k - d) / n;
    }
    cout << "YES" << endl;
    return 0;
}
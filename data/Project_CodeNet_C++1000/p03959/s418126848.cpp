#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    ll t[n], a[n];
    REP(i,n){
        cin >> t[i];
    }
    REP(i,n){
        cin >> a[i];
    }
    ll cnt_t[n], cnt_a[n];
    REP(i,n){
        cnt_t[i] = 1;
        cnt_a[i] = 1;
    }
    ll mx = 0;
    REP(i,n){
        if(t[i] <= mx){
            cnt_t[i] = t[i];
        }else{
            if(t[i] > a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        mx = max(mx, t[i]);
    }
    mx = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] <= mx){
            cnt_a[i] = a[i];
        }else{
            if(a[i] > t[i]){
                cout << 0 << endl;
                return 0;
            }
        }
        mx = max(mx, a[i]);
    }
    ll ans = 1;
    REP(i,n){
        ans *= min(cnt_t[i], cnt_a[i]);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
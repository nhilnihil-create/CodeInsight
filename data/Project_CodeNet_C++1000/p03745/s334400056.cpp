#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n, 0);
    REP(i, n) cin >> a[i];

    int inc = -1;
    ll ans = 1;

    REP(i, n-1){
        if (a[i] == a[i+1]) continue;
        else if (a[i] > a[i+1]){
            
            if (inc == 1){
                ans++;
                inc = -1;
            }
            else inc = 0;
            
        }
        else{
            if (inc == 0){
                ans++;
                inc = -1;
            }
            else inc = 1;
        }
    }
    cout << ans << endl;
}

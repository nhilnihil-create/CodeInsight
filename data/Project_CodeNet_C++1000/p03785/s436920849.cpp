#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    int n, c, k;
    cin >> n >> c >> k;
    vector<ll>t(n, 0);
    REP(i, n) {
        cin >> t[i];   
    }
    sort(ALL(t));

    ll curr = 0;
    ll ans = 0;

    while(curr < n){
        ll firstPassenger = curr;
        bool ok = true;
        ll on = 1;
        curr++;

        while (ok){
            if (t[curr] <= t[firstPassenger]+k) on++;
            else {
                ok = false;
                continue;
            }

            if (on > c) {
                ok = false;
                continue;
            }

            curr++;
        }
        ans++;
    }
    cout << ans << endl;
    
}
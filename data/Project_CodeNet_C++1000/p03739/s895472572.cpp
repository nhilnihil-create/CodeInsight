#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int n; cin >> n;
    
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }

    if(a[0] != 0){
        ll now = 0;
        ll ans1 = 0;
        now += a[0];
        for (int i = 1; i < n; i++){
            ll nex = now + a[i];
            if(now > 0){
                if(nex >= 0){
                    now = -1;
                    ans1 += nex + 1;
                } else {
                    now = nex;
                }
            } else {
                if(nex <= 0){
                    now = 1;
                    ans1 += 1 - nex;
                } else {
                    now = nex;
                }
            }
        }

        ll ans2;
        if(a[0] > 0){
            now = -1;
            ans2 = a[0] + 1;
        } else {
            now = 1;
            ans2 = 1 - a[0];
        }
        for (int i = 1; i < n; i++){
            ll nex = now + a[i];
            if(now > 0){
                if(nex >= 0){
                    now = -1;
                    ans2 += nex + 1;
                } else {
                    now = nex;
                }
            } else {
                if(nex <= 0){
                    now = 1;
                    ans2 += 1 - nex;
                } else {
                    now = nex;
                }
            }
        }

        cout << min(ans1, ans2) << endl;

    } else {
        ll now = 0;
        ll ans1 = 1;
        now = 1;
        for (int i = 1; i < n; i++){
            ll nex = now + a[i];
            if(now > 0){
                if(nex >= 0){
                    now = -1;
                    ans1 += nex + 1;
                } else {
                    now = nex;
                }
            } else {
                if(nex <= 0){
                    now = 1;
                    ans1 += 1 - nex;
                } else {
                    now = nex;
                }
            }
        }

        now = -1;
        ll ans2 = 1;
        for (int i = 1; i < n; i++){
            ll nex = now + a[i];
            if(now > 0){
                if(nex >= 0){
                    now = -1;
                    ans2 += nex + 1;
                } else {
                    now = nex;
                }
            } else {
                if(nex <= 0){
                    now = 1;
                    ans2 += 1 - nex;
                } else {
                    now = nex;
                }
            }
        }

        cout << min(ans1, ans2) << endl;
    }

    return 0;
}
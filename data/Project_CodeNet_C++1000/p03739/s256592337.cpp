#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    auto f = [&](bool f) {
        ll res = 0, sum = 0;
        if(f) {
            if(a[0] > 0) sum = a[0];
            else {
                res += 1 - a[0];
                sum = 1;
            }
        } else {
            if(a[0] < 0) sum = a[0];
            else {
                res += a[0] - (-1);
                sum = -1;
            }
        }
        cerr << sum << " ";
        rep(i, 1, n){
            if(sum < 0) {
                if(sum + a[i] > 0) {
                    sum += a[i];
                } else {
                    sum += a[i];
                    res += 1 - sum;
                    sum = 1;
                }
            } else {
                if(sum + a[i] < 0){
                    sum += a[i];
                } else {
                    sum += a[i];
                    res += sum - (-1);
                    sum = -1;
                }
            }
            cerr << sum << " ";
        }
        cerr << endl;
        return res;
    };
    cerr << f(true) << endl;
    cerr << f(false) << endl;
    cout << min(f(true), f(false)) << endl;
    return 0;
}
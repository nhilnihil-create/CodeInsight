//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    --n;

    bool flag = true;
    if(abs(a-b) > n*d) flag = false;
    else {
        int x = c+d;
        if(!(1&n)) {
            int res = abs(a-b)%x;
            if((n/2+1)*c-(n/2-1)*d > res && n/2*d-n/2*c < res) {
                flag = false;
            }
        } else {
            int res = abs(a-b)%x;
            if((n/2+1)*c-n/2*d > res || (n/2+1)*d-n/2*c < res) {
                flag = false;
            }
        }
    }

    cout << (flag ? "YES":"NO") << endl;
}
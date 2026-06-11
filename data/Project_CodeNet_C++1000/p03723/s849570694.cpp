#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    int64_t a,b,c;
    cin >> a >> b >> c;
    int64_t ca=a,cb=b,cc=c;
    int64_t ca_=a,cb_=b,cc_=c;
    int64_t res = 0;
    while(true){
        // cout << "ca:" << ca << " cb:" << cb << " cc:" << cc << endl;
        if(ca%2!=0 || cb%2!=0 || cc%2!=0) break;
        ca_ = cb/2 + cc/2;
        cb_ = ca/2 + cc/2;
        cc_ = ca/2 + cb/2;
        ca = ca_;
        cb = cb_;
        cc = cc_;
        res++;
        if(ca==a && cb==b && cc==c) {
            res = -1;
            break;
        }
    }
    cout << res << endl;
}
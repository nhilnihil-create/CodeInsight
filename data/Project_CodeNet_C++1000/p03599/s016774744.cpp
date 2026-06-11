#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vout(x) rep(i,x.size()) cout << x[i] << " "
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1LL<<62;
const int MAX = 1e5;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    double concent = -1;
    int ans_l, ans_r;
    for (int w = 0; 100*a*w <= f; w++) {
        for (int x = 0; 100*b*x <= f; x++) {
            for (int y = 0; c*y <= (a*w+b*x)*e; y++) {
                for (int z = 0; d*z <= (a*w+b*x)*e; z++) {
                    if (100*a*w+100*b*x+c*y+d*z > f) continue;
                    if (c*y+d*z > (a*w+b*x)*e) continue;
                    int water = 100*a*w + 100*b*x;
                    int sugar = c*y + d*z;
                    if (chmax(concent,(double)sugar/(water+sugar))) {
                        ans_l = water+sugar;
                        ans_r = sugar;
                    }
                }
            }
        }
    }
    if (concent != -1) cout << ans_l << " " << ans_r << endl;
    else cout << f << " " << 0 << endl;
}
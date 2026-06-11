#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()




int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double M = 0;
    int ans_w = 100 * a;
    int ans_s = 0;
    vector<int> water_sizes(31, 0);
    rep (i, 31) {
        rep (j, 31) {
            int water_size = i * a + j * b;
            if (water_size >= 31) continue;
            water_sizes[water_size] = 1;
        }
    }
    rep (water_size, 1, water_sizes.size()) {
        if(water_sizes[water_size] == 0) {
            continue;
        }
        int sugar_capacity = e * water_size;
        rep (sugar_size, sugar_capacity+1) {
            if (water_size * 100 + sugar_size > f) {
                break;
            }
            bool sugar_configurable = false;
            for (int c_i = 0; c_i * c <= sugar_size; ++c_i) {
                if ((sugar_size - c_i * c) % d == 0) {
                    sugar_configurable = true;
                    break;
                }
            }
            if (sugar_configurable) {
                if (chmax(M, 1.0 * sugar_size / (water_size * 100 + sugar_size))) {
                    ans_w = water_size * 100;
                    ans_s = sugar_size;
                }
            }
        }
    }
    cout << ans_w + ans_s << " " << ans_s << endl;
}


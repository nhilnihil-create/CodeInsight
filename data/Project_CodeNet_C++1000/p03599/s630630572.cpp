#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    set<int> s;
    rp(i, 0, 3000) {
        rp(j, 0, 3000) {
            if(i*c + j*d > f) break;
            s.insert(i*c + j*d);
        }
    }
    vector<int> sugar_list(s.begin(), s.end());
    int mass = 100*a;
    int res = 0;
    rp(i, 0, 30) {
        rp(j, 0, 30) {
            int water = i*a*100 + j*b*100;
            int limit = min(f - water, (water/100) * e);
            int ok = -1; int ng = sugar_list.size();
            while(abs(ok - ng) > 1) {
                int x = (ok + ng) / 2;
                if(sugar_list[x] <= limit) ok = x;
                else ng = x;
            }
            int sugar = 0;
            if(ok >= 0) sugar = sugar_list[ok];
            if(mass*sugar > (water + sugar) * res){
                mass = water + sugar;
                res = sugar;
            }
        }
    }
    printf("%d %d\n", mass, res);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;
int main()
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    double ans = 0;
    int ans1 = 0, ans2 = 0;
    rep(a, 31) {
        rep(b, 31) {
            int water = a * A * 100 + b * B * 100;
            if (water > F) continue;
            int able_sugar = E * (water / 100);
            able_sugar = min(F - water, able_sugar);
            rep(c, 3001) {
                int sugarc = c * C;
                int sugard = D * ((able_sugar - sugarc) / D);
                int sugar = sugarc + sugard;
                if (water + sugar == 0 || able_sugar < sugar || sugard < 0 || water + sugar > F) continue;
                double sugarwater = (100.0 * sugar) / (water + sugar);
                if (ans <= sugarwater) {
                    // cout << able_sugar << " " << a << " " << b << " " << sugarc << " " << sugard << endl;
                    ans = sugarwater;
                    ans1 = water + sugar;
                    ans2 = sugar;
                }
            }
        }
    }

    cout << ans1 << " " << ans2 << endl;
    return 0;
}
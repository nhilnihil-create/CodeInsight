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

    int water = 0, sugar = 0;
    double nax = 0.0;
    int answ = 0, anss = 0;
    rep(i, 31) {
        rep(j, 31) {
            for (int k = 0; k <= 3000; k += C) {
                water = i * 100 * A + j * 100 * B;
                int wg = water / 100;
                if (wg * E < k) continue;
                int rest = wg * E - k;
                chmin(rest, F - water - k);
                sugar = k + D * (rest / D);
                if (water + sugar > F) continue;
                double concent = (double)100 * sugar / (double)(water + sugar);
                if (nax < concent) {
                    answ = water;
                    anss = sugar;
                    nax = concent;
                }
            }
        }
    }

    if (answ == 0) {
        answ = 100 * min(A, B);
    }

    cout << answ + anss << " " << anss << endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    string S; cin >> S;
    reverse(S.begin(), S.end());
    string T[4] = {"dream", "dreamer", "erase", "eraser"};
    rep(i, 4) reverse(T[i].begin(), T[i].end());
    rep(i, S.size()) {
        bool isMake = false;
        rep(j, 4) {
            bool ok = true;
            rep(k, T[j].size()) {
                if(S[i + k] != T[j][k]) ok = false;
            }
            if(ok) {
                i += T[j].size() - 1;
                isMake = true;
                break;
            }
        }
        if(!isMake) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}

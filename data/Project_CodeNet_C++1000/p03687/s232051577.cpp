#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 6;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    string s; cin >> s;
    int ans = 101;
    for(char c = 'a'; c <= 'z'; ++c) {
        string check = "";
        rep(i, s.size()) check += c;
        string tmp = s;
        int cnt = 0;
        while(tmp != check) {
            rep(i, tmp.size()) {
                if(tmp[i] == c && i != 0) {
                    tmp[i - 1] = c;
                }
            }
            tmp.pop_back();
            check.pop_back();
            ++cnt;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

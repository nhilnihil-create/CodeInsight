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
    int N; cin >> N;
    string s; cin >> s;
    char animal[2] = {'W', 'S'};
    for(char a1 : animal) {
        for(char a2 : animal) {
            vector<char>ans;
            ans.pb(a1);
            ans.pb(a2);
            for(int i = 1; i <= N; ++i) {
                if(s[i%N] == 'o') {
                    if(ans[i] == 'S') {
                        ans.pb(ans[i - 1]);
                    }else {
                        ans.pb(((ans[i - 1] == 'S') ? 'W' : 'S'));
                    }
                }else {
                    if(ans[i] == 'S') {
                        ans.pb(((ans[i - 1] == 'S') ? 'W' : 'S'));
                    }else {
                        ans.pb(ans[i - 1]);
                    }
                }
            }
            if(ans[0] == ans[N] && ans[1] == ans[N + 1]) {
                rep(i, N) {
                    cout << ans[i];
                }
                return 0;
            }
        }
    }
    cout << -1 << endl;
}

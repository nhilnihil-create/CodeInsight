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
#define Pint pair<int, int>
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
/* -- template -- */

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>>G(N);
    deque<int> Q;
    vector<bool>visited(N, false);
    rep(i, M) {
        int a, b; cin >> a >> b;
        G[--a].pb(--b);
        G[b].pb(a);
        if(i == 0) {
            Q.push_back(a);
            Q.push_back(b);
            visited[a] = visited[b] = true;
        }
    }
    bool checkflg = true;
    while(checkflg) {
        checkflg = false;
        bool flg = true;
        int i = Q.front();
        for(int v : G[i]) {
            if(visited[v] == false) {
                checkflg = true;
                if(flg) {
                    Q.push_front(v);
                    flg = false;
                    visited[v] = true;
                    break;
                }
            }
        }
        flg = true;
        int j = Q.back();
        for(int v : G[j]) {
            if(visited[v] == false) {
                checkflg = true;
                if(flg) {
                    Q.push_back(v);
                    flg = false;
                    visited[v] = true;
                    break;
                }
            }
        }
    }
    cout << Q.size() << endl;
    rep(i, Q.size()) {
        cout << Q[i] + 1 << ' ';
    }
}

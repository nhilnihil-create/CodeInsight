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
    int a[M], b[M];
    vector<int> imos(N + 1, 0);
    rep(i, M) {
        cin >> a[i] >> b[i];
        imos[a[i] - 1] += 1;
        imos[b[i] - 1] += -1;
    }
    bool ok = true;
    rep(i, N) {
        imos[i + 1] += imos[i];
        if(imos[i + 1] % 2) ok = false;
    }
    if(M == 1) ok = false;
    if(ok) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}

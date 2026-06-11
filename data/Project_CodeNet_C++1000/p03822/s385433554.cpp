#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

const int MX_N = 1e5+5;

int N;
vector<int> al[MX_N];

int dfs(int u) {
    vector<int> vec;
    for (int& v : al[u]) {
        vec.push_back(dfs(v));
    }
    sort(ALL(vec));
    int ret = 0;
    FOR(i,0,SZ(vec)-1){
        ret = max(ret, vec[i]+SZ(vec)-i);
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    FOR(i,2,N){
        int P; cin >> P;
        al[P].push_back(i);
    }

    cout << dfs(1);
}


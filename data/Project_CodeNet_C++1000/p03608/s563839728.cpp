#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
static const int INF = 1e9;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<int> reg(r);
    for(int ir=0;ir<r;ir++) {
        cin >> reg.at(ir); reg.at(ir)--;
    }

    int a, b, c;
    vector<vector<int>> adjmat(n, vector<int>(n, INF));
    for(int im=0;im<m;im++) {
        cin >> a >> b >> c; a--; b--;
        if(adjmat.at(a).at(b)>c) {
            adjmat.at(a).at(b) = c;
            adjmat.at(b).at(a) = c;
        }
    }

    for(int kn=0;kn<n;kn++) {
        for(int in=0;in<n;in++) {
            for(int jn=0;jn<n;jn++) {
                if(adjmat.at(in).at(jn)>adjmat.at(in).at(kn)+adjmat.at(kn).at(jn)) {
                    adjmat.at(in).at(jn)=adjmat.at(in).at(kn)+adjmat.at(kn).at(jn);
                }
            }
        }
    }

    vector<int> V;
    for(int ir=0;ir<r;ir++) {
        V.push_back(ir);
    }

    int ans = INF, anstmp;
    do {
        int pre, next;
        anstmp = 0;
        for(int ir=0;ir<r-1;ir++) {
            pre = reg.at(V.at(ir));
            next = reg.at(V.at(ir+1));
            anstmp += adjmat.at(pre).at(next);
        }
        chmin(ans, anstmp);
    } while(next_permutation(V.begin(), V.end()));
    cout << ans << endl;
    return 0;
}

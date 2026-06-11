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

vector<int> reg;
vector<int> visited(8);
vector<vector<int>> adjmat;
int ans = INF, n, m ,r;

void dfs(vector<int> &a) {
    if(a.size()==r) {
        int anstmp = 0, pre, next;
        for(int ir=0;ir<r-1;ir++) {
            pre = a.at(ir);
            next = a.at(ir+1);
            anstmp += adjmat.at(pre).at(next);
        }
        chmin(ans, anstmp);
        return;
    }

    for(int v=0;v<r;v++) {
        if(visited.at(v)==false) {
            visited.at(v) = true;
            a.push_back(reg.at(v));
            dfs(a);
            a.pop_back();
            visited.at(v) = false;
        }
    }
}

int main(void) {
    cin >> n >> m >> r;
    
    reg.resize(r);
    for(int ir=0;ir<r;ir++) {
        cin >> reg.at(ir); reg.at(ir)--;
    }

    int a, b, c;
    adjmat.resize(n, vector<int>(n, INF));
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

    vector<int> argv;
    dfs(argv);
    cout << ans << endl;
    return 0;
}

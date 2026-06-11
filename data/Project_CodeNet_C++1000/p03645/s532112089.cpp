#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=3.14159265358979323846;

int main () {
    int N, M;
    cin >> N >> M;

    int a[M], b[M];
    set<int> s2;
    set<int> g2;
    rep(i,0,M) {
        cin >> a[i] >>  b[i];

        if (a[i]==1) {
            s2.insert(b[i]);
        }
        if (b[i]==1) {
            s2.insert(a[i]);
        }
        if (a[i]==N) {
            g2.insert(b[i]);
        }
        if (b[i]==N) {
            g2.insert(a[i]);
        }
    }

    bool ans = false;

    for (auto p :s2) {
        if (g2.count(p)) {
            ans = true;
        }
    }
    if (ans) {
        cout << "POSSIBLE" << endl;
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
}
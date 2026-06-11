#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(m);
    vector<int> d(m);
    for(int in=0;in<n;in++) {
        cin >> a.at(in) >> b.at(in);
    }
    for(int im=0;im<m;im++) {
        cin >> c.at(im) >> d.at(im);
    }

    int ans, dis, distmp;
    for(int in=0;in<n;in++) {
        ans = 0;
        dis = 1e9;
        distmp;
        for(int im=0;im<m;im++) {
            distmp = abs(a.at(in)-c.at(im)) + abs(b.at(in)-d.at(im));
            if(dis>distmp) {
                dis = distmp;
                ans = im+1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

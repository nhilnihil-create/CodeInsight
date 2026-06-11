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
    int n;
    cin >> n;

    vector<int> t(n);
    int sum = 0;
    for(int in=0;in<n;in++) {
        cin >> t.at(in);
        sum += t.at(in);
    }

    int m;
    cin >> m;
    vector<int> p(m);
    vector<int> x(m);
    for(int im=0;im<m;im++) {
        cin >> p.at(im) >> x.at(im);
        p.at(im)--;
    }
    for(int im=0;im<m;im++) {
        cout << sum - t.at(p.at(im)) + x.at(im) << endl;
    }
    return 0;
}

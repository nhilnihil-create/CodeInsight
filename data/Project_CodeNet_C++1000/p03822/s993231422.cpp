#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()

using namespace std;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> g(N);
    FOR(i, 1, N) {
        int a;
        cin >> a;
        --a;
        g[a].push_back(i);
    }

    function<int(int)> f = [&](int u) {
        vector<int> fs;
        for (int v: g[u]) {
            fs.push_back(f(v));
        }
        sort(all(fs));
        int result = 0;
        REP(i, fs.size()) {
            amax(result, fs.size() - i + fs[i]);
        }
        return result;
    };

    cout << f(0) << endl;

    return 0;
}
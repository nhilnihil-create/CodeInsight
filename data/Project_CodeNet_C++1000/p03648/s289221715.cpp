#include <bits/stdc++.h>

#define LL long long
#define VI vector<int>
#define VB vector<bool>
#define VL vector<long long>
#define FOR(i,a,b) for(int i= (a); i<((int)b); ++i)
#define RFOR(i,a) for(int i=(a); i >= 0; --i)
#define FOE(i,a) for(auto i : a)
#define ALL(c) (c).begin(), (c).end()
#define RALL(c) (c).rbegin(), (c).rend()
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v,x) (std::find(v.begin(), v.end(), x) != v.end())
#define BIT(n) (1LL<<(n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define EPS 1e-14

const std::string YES = "YES";
const std::string Yes = "Yes";
const std::string NO = "NO";
const std::string No = "No";

using namespace std;


int solve(LL K) {
    vector<LL> v(50, 49);

    LL num = K / 50;
    FOR(i, 0, v.size()) {
        v[i] += num;
    }

    LL rest = K % 50;
    FOR(i, 0, rest) {
        v[i] += 50;
        FOR(j, 0, 50) {
            if (i != j) {
                v[j] -= 1;
            }
        }
    }

    cout << 50 << endl;
    FOE(x, v) {
        cout << x << endl;
    }
}


int main() {
    LL K;
    cin >> K;
    solve(K);

    return 0;
}
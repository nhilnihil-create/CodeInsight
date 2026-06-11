#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

int main() {
    int N, W; cin >> N >> W;
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];
    map<long long, int> cur;
    cur[0] = 0;
    for (int i = 0; i < N; i++) {
        map<long long, int> nxt;
        for (auto &p: cur) {
            chmax(nxt[p.first], p.second);
            if (p.first + w[i] <= W) chmax(nxt[p.first + w[i]], p.second + v[i]);
        }
        swap(cur, nxt);
    }
    int ma = 0;
    for (auto &p: cur) chmax(ma, p.second);
    cout << ma << endl;
    return 0;
}
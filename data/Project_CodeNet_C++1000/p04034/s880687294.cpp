#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
    int N, M; cin >> N >> M;
    vector<int> V(N,1);
    set<int> Red;
    Red.insert(0);
    rep(i,M) {
        int x, y; cin >> x >> y;
        x--,y--;
        if (Red.count(x) > 0) {
            if (V[x] == 1) {
                Red.erase(x);
                Red.insert(y);
            } else {
                Red.insert(y);
            }
        }
        V[x]--;
        V[y]++;
    }
    cout << Red.size() << endl;
}

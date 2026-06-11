#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    
    vector<int> mizu(3010, 0);
    mizu[0] = 1;
    rep(i, 3010) {
        if (!mizu[i]) continue;
        if (i + 100 * A < 3010) mizu[i + 100 * A] = 1;
        if (i + 100 * B < 3010) mizu[i + 100 * B] = 1;
    }
    vector<int> water;
    REP(i, 3010) {
        if (mizu[i] && i <= F) water.push_back(i);
    }
    vector<int> sato(3010, 0);
    sato[0] = 1;
    rep(i, 3010) {
        if (!sato[i]) continue;
        if (i + C < 3010) sato[i + C] = 1;
        if (i + D < 3010) sato[i + D] = 1;
    }
    vector<int> sugar;
    rep(i, 3010) {
        if (sato[i] && i <= F) sugar.push_back(i);
    }
    
    double max_nodo = 0;
    int max_water = 0, max_sugar = 0;
    for (int w : water) {
        auto iter = upper_bound(sugar.begin(), sugar.end(), min(w / 100 * E, F - w)) - 1;
        int s = *iter;
        if ((double)s / (s + w) >= max_nodo) {
            max_water = w;
            max_sugar = s;
            max_nodo = (double)s / (s + w);
        }
    }
    cout << max_water + max_sugar << " " << max_sugar << endl;
    return 0;
}

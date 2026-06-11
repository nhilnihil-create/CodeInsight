#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int64_t N, W, w0 = 1000000000;
    cin >> N >> W;
    vector< vector<int64_t> > V(4);
    while(N--) {
        int64_t w, v;
        cin >> w >> v;
        w0 = min(w0, w);
        V[w-w0].push_back(v);
    }

    for(auto &e: V) {
        sort(e.begin(), e.end());
        e.push_back(0);
        reverse(e.begin(), e.end());
        partial_sum(e.begin(), e.end(), e.begin());
    }

    int64_t ans = 0;
    for(int64_t i=0; i<V[0].size(); i++) {
        for(int64_t j=0; j<V[1].size(); j++) {
            for(int64_t k=0; k<V[2].size(); k++) {
                for(int64_t l=0; l<V[3].size(); l++) {
                    if(w0*(i+j+k+l) + j + 2*k + 3*l <= W) {
                        ans = max(ans, V[0][i] + V[1][j] + V[2][k] + V[3][l]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

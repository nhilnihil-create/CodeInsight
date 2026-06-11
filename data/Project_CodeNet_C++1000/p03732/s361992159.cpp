#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct object {
    int64_t weight;
    int64_t value;
};

int main(void) {
    int64_t N, W;
    cin >> N >> W;
    vector< object > v(N);
    for(int64_t i=0; i<N; i++) {
        cin >> v[i].weight >> v[i].value;
    }
    vector< vector<int64_t> > v2(4);
    for(int64_t i=0; i<N; i++) {
        int64_t d = v[i].weight - v[0].weight;
        v2[d].push_back(v[i].value);
    }
    for(int64_t i=0; i<4; i++) {
        sort(v2[i].rbegin(), v2[i].rend());
        partial_sum(v2[i].begin(), v2[i].end(), v2[i].begin());
        v2[i].insert(v2[i].begin(), 0);
    }

    int64_t ans = 0;
    for(int64_t i=0; i<v2[0].size(); i++) {
        for(int64_t j=0; j<v2[1].size(); j++) {
            for(int64_t k=0; k<v2[2].size(); k++) {
                for(int64_t l=0; l<v2[3].size(); l++) {
                    if(v[0].weight*(i+j+k+l) + j + 2*k + 3*l <= W) {
                        ans = max(ans, v2[0][i] + v2[1][j] + v2[2][k] + v2[3][l]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N; long long W;
    cin >> N >> W;

    vector<long long> val[4];

    long long w, v;
    cin >> w >> v;
    long long w0 = w;
    val[0].push_back(v);

    for (int i = 1; i < N; i++) {
        cin >> w >> v;

        int rem = w - w0;
        val[rem].push_back(v);
    }

    for (int i = 0; i < 4; i++) {
        sort(val[i].begin(), val[i].end(), greater<long long>());
        for (int j = 1; j < val[i].size(); j++) {
            val[i][j] = val[i][j - 1] + val[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        val[i].insert(val[i].begin(), 0);
    }

    long long ans = 0;
    for (int i = 0; i < val[0].size(); i++) {
        for (int j = 0; j < val[1].size(); j++) {
            for (int k = 0; k < val[2].size(); k++) {
                for (int l = 0; l < val[3].size(); l++) {
                    long long sum = w0*i + (w0 + 1)*j + (w0 + 2)*k + (w0 + 3)*l;
                    if (sum <= W) {
                        ans = max(ans, val[0][i] + val[1][j] + val[2][k] + val[3][l]);
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
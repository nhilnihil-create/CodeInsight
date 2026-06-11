#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int64_t N, A, ans = 0;
    cin >> N >> A;
    vector<vector<vector<int64_t>>> X(N + 1, vector<vector<int64_t>> (2501, vector<int64_t> (50)));
    for (int i = 0; i < N; i++) {
        int64_t a;
        cin >> a;
        for (int j = 0; j < 2451; j++) {
            if (j == 0) {
                X.at(i + 1).at(a).at(0)++;
                continue;
            }
            for (int k = 1; k < 50; k++){
                if (X.at(i).at(j).at(k - 1) != 0) {
                    X.at(i + 1).at(j + a).at(k) += X.at(i).at(j).at(k - 1);
                }
            }
        }
        if (i != N - 1) {
            X.at(i + 2) = X.at(i + 1);
        }
    }
    for (int i = 1; i < 2501; i++) {
        for (int j = 0; j < 50; j++) {
            if (i / (j + 1) == A && i % (j + 1) == 0) {
                ans += X.at(N).at(i).at(j);
            }
        }
    }
    cout << ans << endl;
}

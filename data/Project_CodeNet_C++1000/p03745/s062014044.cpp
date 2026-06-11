#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<map>
#include<set>

using namespace std;
using ll = long long;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
const double PI = 4.0 * atan(1.0);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, a, n) for (int i = a; i <= (n); ++i)

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    
    int ans = 0;
    string mode = ""; // 空(neutral), i(increase), d(decrease)
    for (int i = 0; i < N; i++) {
        if (i == 0) {
            ans++;
            continue;
        }

        int diff = A[i] - A[i - 1];
        if (diff < 0) {
            if (mode == "") {
                mode = "d";
            } else if (mode == "i") {
                ans++;
                mode = "";
            }
        } else if (diff > 0) {
            if (mode == "") {
                mode = "i";
            } else if (mode == "d"){
                ans++;
                mode = "";
            }
        }
    }
    cout << ans << endl;
    return 0;
}

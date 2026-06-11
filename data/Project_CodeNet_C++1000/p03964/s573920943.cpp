#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    int64_t N;
    cin >> N;
    Pll ans = make_pair(1, 1);
    for (int i = 0; i < N; i++) {
        int64_t a, b;
        cin >> a >> b;
        int64_t j = max(ans.first / a, ans.second / b);
        if (j == ans.first / a && ans.first % a != 0) {
            j++;
        }
        if (j == ans.second / b && ans.second % b != 0) {
            j++;
        }
        ans = make_pair(a * j, b * j);
    }
    cout << ans.first + ans.second << endl;
}

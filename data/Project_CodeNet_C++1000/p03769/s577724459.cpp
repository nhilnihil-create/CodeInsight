// AtCoder Grand Contest 012
// C - Tautonym Puzzle

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_C = 100;

ll N;
vector<int> ans;

int main() {

    cin >> N;

    for (int i = 0; ((N + 1) >> i) > 1; i++) {
        if (((N + 1) >> i) & 1) {
            ans.push_back(MAX_C - i);
        }
        ans.push_back(i + 1);
    }
    for (int i = 0; i < MAX_C; i++) {
        ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i == (int)ans.size() - 1 ? '\n' : ' ');
    }

    return 0;

}

#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> can_reach_from_1;
    vector<int> can_reach_to_n;
    vector<pair<int, int>> link;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        link.emplace_back(a, b);
        if (a == 1) can_reach_from_1.push_back(b);
        if (b == n) can_reach_to_n.push_back(a);
    }

    sort(can_reach_from_1.begin(), can_reach_from_1.end());
    sort(can_reach_to_n.begin(), can_reach_to_n.end());

    bool ans = false;
    for (int i = 0; i < can_reach_from_1.size(); i++) {
        ans = binary_search(can_reach_to_n.begin(), can_reach_to_n.end(), can_reach_from_1[i]);
        if(ans) break;
    }

    cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; int64_t k;
    cin >> n >> k;

    vector<pair<int, int>> p(n);
    for (auto i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        p[i] = {a, b};
    }
    sort(p.begin(), p.end());

//    int64_t sum = 0;
//    for (auto i = 0; i < n; i++) {
//        sum += p[i].second;
//        if(sum >= k) {
//            cout << p[i].first << endl;
//            return 0;
//        }
//    }

    vector<pair<int64_t, int>> q;
    int64_t prev = 0;
    for (auto i = 0; i < n; i++) {
        q.emplace_back(p[i].second + prev, p[i].first);
        prev += p[i].second;
        // cout << p[i].first << " " << p[i].second << endl;
    }
    auto itr = lower_bound(q.begin(), q.end(), make_pair(k, 0));
    cout << itr->second << endl;

    return 0;
}
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

    int64_t sum = 0;
    for (auto i = 0; i < n; i++) {
        sum += p[i].second;
        if(sum >= k) {
            cout << p[i].first << endl;
            return 0;
        }
    }

    return 0;
}
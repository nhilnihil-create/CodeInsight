#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<long long, long long> List[4];
    for(size_t i = 0; i < 4; ++i) {
        cin >> List[i].second;
    }
    List[0].first = 1, List[1].first = 2, List[2].first = 4, List[3].first = 8;
    sort(List, List + 4, [&](auto &a, auto &b){ return a.second * b.first < b.second * a.first; });
    /*
    for(size_t i = 0; i < 4; ++i) {
        cout << List[i].first << " " << List[i].second << endl;
    }
    */
    long long N;
    cin >> N;
    N *= 4LL;
    long long res = 0LL;
    for(int i = 0; i < 4; ++i) {
        long long p = N/List[i].first;
        res += p*List[i].second;
        N -= p*List[i].first;
    }
    cout << res << endl;
    return 0;
}

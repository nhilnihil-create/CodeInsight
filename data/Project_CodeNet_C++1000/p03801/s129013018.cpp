#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    vector< pair<int64_t,int> > p(N);
    for(int i=0; i<N; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    p.emplace_back(0, 0);
    sort(p.rbegin(), p.rend());

    vector<int64_t> ans(N);
    int m = numeric_limits<int>::max();
    for(int i=0; i<N; i++) {
        m = min(m, p[i].second);
        ans[m] += (i+1L) * (p[i].first - p[i+1].first);
    }

    for(auto e: ans) {
        cout << e << endl;
    }
    return 0;
}

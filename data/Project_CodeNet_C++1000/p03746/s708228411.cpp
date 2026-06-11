#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long N, M;
    cin >> N >> M;
    vector<vector<unsigned long>> edges(N);
    for (unsigned long i = 0, a, b; i < M; ++i) {
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<unsigned long> used(N);
    deque<unsigned long> ans({0});
    unsigned long beg = 0;
    used[0] = 1;

    while([&edges, &beg, &used, &ans]{
        for(const auto i : edges[beg])
            if(!used[i]){
                used[beg = i] = 1;
                ans.push_back(beg);
                return true;
            }
        return false;
    }());

    beg = 0;

    while([&edges, &beg, &used, &ans]{
        for(const auto i : edges[beg])
            if(!used[i]){
                used[beg = i] = 1;
                ans.push_front(beg);
                return true;
            }
        return false;
    }());

    cout << ans.size() << endl;
    for(const auto i : ans)cout << i + 1 << " ";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long N, M;
    cin >> N >> M;
    vector<vector<unsigned long>> edges(N);
    for (unsigned long i = 0, a, b; i < M; ++i) {
        cin >> a >> b;
        edges[--a].push_back(--b);
        edges[b].push_back(a);
    }

    vector<unsigned long> used(N);
    vector<unsigned long> ans({0});
    used[0] = 1;
    
    for(unsigned long beg = 0, iter = 2; iter--; beg = 0){
        while([&edges, &beg, &used, &ans]{
            for(const auto i : edges[beg])
                if(!used[i]){
                    used[beg = i] = 1;
                    ans.push_back(beg);
                    return true;
                }
            return false;
        }());
        reverse(ans.begin(), ans.end());
    }

    cout << ans.size() << endl;
    for(const auto i : ans)cout << i + 1 << " ";

    return 0;
}
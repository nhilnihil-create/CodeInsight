#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n;
    cin >> n;
    vector<long> a(n-1);
    for(auto &e: a) cin >> e, e--;

    vector<set<long>> lose(n);
    for(long i=0; i<n-1; i++)
        lose[a[i]].insert(i+1);

    {
        auto dfs = [&](auto dfs, long cur) -> long {
            vector<long> v;
            for(auto &w: lose[cur])
                v.push_back(dfs(dfs, w) + 1);
            sort(v.begin(), v.end(), greater<>());

            long r = 0;
            for(long i=0; i<v.size(); i++)
                r = max(r, v[i] + i);
            return r;
        };
        cout << dfs(dfs, 0) << endl;
    }
}

#include<bits/stdc++.h>

int main() {
    using namespace std;
    unsigned long N;
    cin >> N;
    vector<unsigned long> a(N);
    for(auto& i : a)cin >> i;
    map<unsigned long, pair<unsigned long, pair<unsigned long, unsigned long>>> m;
    unsigned long cnt{0};
    for(const auto& i : a){
        auto it = m.lower_bound(i);
        if(it == m.end()){
            m.emplace(i, pair<unsigned long, pair<unsigned long, unsigned long>>{cnt, pair<unsigned long, unsigned long>{1, 0}});
        }else{
            ++it->second.second.first;
            it->second.second.second += it->first - i;
        }
        ++cnt;
    }
    vector<unsigned long> v(N), o(N), c(N);
    {
        vector<pair<unsigned long, pair<unsigned long, pair<unsigned long, unsigned long>>>> gue(m.rbegin(), m.rend());
        unsigned long M{gue.size()};
        gue.emplace_back();
        for(unsigned long i{0}; i < M; ++i){
            v[gue[i].second.first] = gue[i].second.second.first + (i ? v[gue[i - 1].second.first] : 0);
            c[gue[i].second.first] = gue[i].first - gue[i + 1].first;
            o[gue[i].second.first] = gue[i].second.second.second;
        }
    }
    vector<unsigned long> ans(N);
    for(unsigned long i{0}; i < N; ++i)ans[i] = v[i] * c[i] - o[i];
    copy(ans.begin(), ans.end(), ostream_iterator<unsigned long>(cout, "\n"));
    return 0;
}
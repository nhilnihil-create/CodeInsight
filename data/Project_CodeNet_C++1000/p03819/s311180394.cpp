#include<bits/stdc++.h>

int main() {
    using namespace std;
    unsigned long N, M;
    cin >> N >> M;
    vector<pair<unsigned long, unsigned long>> souv(N);
    for(auto& i : souv){
        cin >> i.first >> i.second;
        --i.first;
    }
    vector<unsigned long> ans(M + 1);
    unsigned long lim{0};
    const auto& add = [&ans, &lim](unsigned long i, unsigned long x) -> void { if(i > lim)ans[i] += x; };
    for(const auto& i : souv){
        lim = i.second - i.first;
        ans[lim] += (i.second / (lim + 1) == i.first / (lim + 1));
        for(unsigned long j{1}, k{i.second}; k > lim; ++j, --k){
            k = min(i.second / j, k);
            j = max(j, i.second / k);
            add(k, i.second / k - i.second / (k + 1));
        }
        for(unsigned long j{1}, k{i.first}; k > lim; ++j, --k){
            k = min(i.first / j, k);
            j = max(j, i.first / k);
            add(k, i.first / (k + 1) - i.first / k);
        }
    }
    partial_sum(ans.rbegin(), ans.rend(), ans.rbegin());
    copy(ans.begin() + 1, ans.end(), ostream_iterator<unsigned long>(cout, "\n"));
    return 0;
}
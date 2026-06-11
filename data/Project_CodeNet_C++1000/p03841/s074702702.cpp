#include<bits/stdc++.h>

int main(){
    using namespace std;
    size_t N;
    cin >> N;
    deque<pair<size_t, size_t>> bef, aft;
    vector<size_t> ans(N * N), a(N);
    for(size_t i = 0, A; i < N;){
        cin >> A;
        if(i)for(size_t j = 0; j < i; ++j)bef.emplace_back(A, i + 1);
        if(++i != N)for(size_t j = i; j < N; ++j)aft.emplace_back(~A, i);
        ans[A - 1] = i;
    }
    sort(bef.begin(), bef.end());
    sort(aft.begin(), aft.end());
    size_t cnt{0UL};
    for_each(ans.begin(), ans.end(), [&bef, &cnt](auto& i){
        ++cnt;
        if(i)return;
        if(bef.empty())return;
        if(bef[0].first < cnt)return;
        i = bef[0].second;
        bef.pop_front();
    });
    ++cnt;
    for_each(ans.rbegin(), ans.rend(), [&aft, &cnt](auto& i){
        --cnt;
        if(i)return;
        if(aft.empty())return;
        if(~aft[0].first > cnt)return;
        i = aft[0].second;
        aft.pop_front();
    });
    if(!aft.empty() || !bef.empty())return 0 & puts("No");
    puts("Yes");
    for(const auto& i : ans)cout << i << " ";
    cout << endl;
    return 0;
}